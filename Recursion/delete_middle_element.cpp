#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s , int k){
    if(k==1){
        s.pop();
        return ;
    }
    int temp = s.top();
    s.pop();
    solve(s , k-1);
    s.push(temp);
    return ;
}

void middle(stack<int> &s){
    if(s.size()==0){
        return ;
    }
    int size = s.size();
    int k =size/2 +1;
    solve(s,k);
    return ;
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);  // Stack: [1,2,3,4,5] (top = 1)

    cout << "Original: ";
    printStack(s);  // 1 2 3 4 5

    middle(s);

    cout << "After deleting middle: ";
    printStack(s);  // 1 2 4 5  (3 removed)

    return 0;
}