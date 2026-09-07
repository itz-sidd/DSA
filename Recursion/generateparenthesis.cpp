#include <iostream>
#include <vector>
using namespace std;

void solve(int nums, string curr, int open, int close, vector<string>& ans){
    
    if(curr.size() == 2*nums){
        ans.push_back(curr);
        return;
    }

    if(open < 2*nums/2){
        solve(nums, curr+'(', open+1, close, ans);
    }

    if(close < open){
        solve(nums, curr+')', open, close+1, ans);
    }
}

vector<string> generate_parenthesis(int n){
    vector<string> ans;
    if(n <= 0) return ans;
    int open = 0;
    int close = 0;
    string curr = "";

    solve(n, curr, open,close,ans);

    return ans;
}

int main() {
    int n = 3;
    vector<string> result = generate_parenthesis(n);

    for (const string& s : result) {
        cout << s << "\n";
    }

    return 0;
}