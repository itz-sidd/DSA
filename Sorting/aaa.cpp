// rd_parser.cpp
#include <bits/stdc++.h>
using namespace std;

/* --- Lexer --- */
enum TokenType { T_NUM, T_ID, T_PLUS, T_MINUS, T_MUL, T_DIV, T_LPAREN, T_RPAREN, T_END, T_INVALID };

struct Token {
    TokenType type;
    string lexeme;
    int pos;
    Token(TokenType t=T_INVALID, string s="", int p=0): type(t), lexeme(s), pos(p) {}
};

class Lexer {
    string s;
    size_t i;
public:
    Lexer(const string &input): s(input), i(0) {}

    void skipWhitespace() {
        while (i < s.size() && isspace(s[i])) ++i;
    }

    Token nextToken() {
        skipWhitespace();
        if (i >= s.size()) return Token(T_END, "", i);

        char c = s[i];

        if (isdigit(c)) {
            size_t start = i;
            while (i < s.size() && (isdigit(s[i]) || s[i]=='.')) ++i;
            return Token(T_NUM, s.substr(start, i-start), start);
        }

        if (isalpha(c) || c == '_') {
            size_t start = i;
            while (i < s.size() && (isalnum(s[i]) || s[i]=='_')) ++i;
            return Token(T_ID, s.substr(start, i-start), start);
        }

        ++i;
        switch(c) {
            case '+': return Token(T_PLUS, "+", i-1);
            case '-': return Token(T_MINUS, "-", i-1);
            case '*': return Token(T_MUL, "*", i-1);
            case '/': return Token(T_DIV, "/", i-1);
            case '(': return Token(T_LPAREN, "(", i-1);
            case ')': return Token(T_RPAREN, ")", i-1);
            default:  return Token(T_INVALID, string(1,c), i-1);
        }
    }
};

/* --- AST --- */
struct Node {
    string label;
    vector<shared_ptr<Node>> children;
    Node(string l): label(l) {}
};

using NodePtr = shared_ptr<Node>;

/* --- Parser (Recursive Descent) --- */
class Parser {
    Lexer lexer;
    Token cur;

    void advance() {
        cur = lexer.nextToken();
    }

    bool accept(TokenType t) {
        if (cur.type == t) {
            advance();
            return true;
        }
        return false;
    }

    bool expect(TokenType t, const string &errMsg) {
        if (cur.type == t) {
            advance();
            return true;
        }
        cerr << "Error: " << errMsg << " at pos " << cur.pos << " got '" << cur.lexeme << "'\n";
        return false;
    }

public:
    Parser(const string &input): lexer(input) {
        advance(); // load first token
    }

    // Grammar:
    // E  -> T E'
    // E' -> + T E' | - T E' | ε
    // T  -> F T'
    // T' -> * F T' | / F T' | ε
    // F  -> ( E ) | number | id

    NodePtr parseE() {
        // E -> T E'
        auto tnode = parseT();
        if (!tnode) return nullptr;
        return parseEPrime(tnode);
    }

    NodePtr parseEPrime(NodePtr left) {
        // E' -> + T E' | - T E' | ε
        while (cur.type == T_PLUS || cur.type == T_MINUS) {
            string op = cur.lexeme;
            advance();
            auto rightT = parseT();
            if (!rightT) return nullptr;
            // combine left and right under op node
            auto opNode = make_shared<Node>(op);
            opNode->children.push_back(left);
            opNode->children.push_back(rightT);
            left = opNode; // new left becomes subtree
        }
        return left;
    }

    NodePtr parseT() {
        // T -> F T'
        auto fnode = parseF();
        if (!fnode) return nullptr;
        return parseTPrime(fnode);
    }

    NodePtr parseTPrime(NodePtr left) {
        // T' -> * F T' | / F T' | ε
        while (cur.type == T_MUL || cur.type == T_DIV) {
            string op = cur.lexeme;
            advance();
            auto rightF = parseF();
            if (!rightF) return nullptr;
            auto opNode = make_shared<Node>(op);
            opNode->children.push_back(left);
            opNode->children.push_back(rightF);
            left = opNode;
        }
        return left;
    }

    NodePtr parseF() {
        // F -> ( E ) | number | id
        if (cur.type == T_LPAREN) {
            advance();
            auto node = parseE();
            if (!node) return nullptr;
            if (!expect(T_RPAREN, "expected ')'")) return nullptr;
            return node;
        }
        if (cur.type == T_NUM) {
            auto n = make_shared<Node>(string("num(") + cur.lexeme + ")");
            advance();
            return n;
        }
        if (cur.type == T_ID) {
            auto n = make_shared<Node>(string("id(") + cur.lexeme + ")");
            advance();
            return n;
        }
        cerr << "Error: expected number, id, or '(' at pos " << cur.pos << " got '" << cur.lexeme << "'\n";
        return nullptr;
    }

    // parse entry
    NodePtr parse() {
        auto root = parseE();
        if (!root) return nullptr;
        if (cur.type != T_END) {
            cerr << "Error: unexpected token after end of expression: '" << cur.lexeme << "' at pos " << cur.pos << "\n";
            return nullptr;
        }
        return root;
    }
};

/* --- Helper to print AST (preorder) --- */
void printAST(const NodePtr &node, int indent=0) {
    if (!node) return;
    for (int i=0;i<indent;i++) cout << "  ";
    cout << node->label << "\n";
    for (auto &c : node->children) printAST(c, indent+1);
}

/* --- main for testing --- */
int main() {
    cout << "Enter an expression to parse (e.g. a + b * (c + 2)):\n";
    string line;
    getline(cin, line);

    Parser p(line);
    auto ast = p.parse();
    if (ast) {
        cout << "Parsing succeeded. AST (preorder):\n";
        printAST(ast);
    } else {
        cout << "Parsing failed.\n";
    }
    return 0;
}
