#include <iostream>
using namespace std;

void solve(int n, char s, char b, char h) {
    if (n == 1) {
        cout << "Moving plate " << n << " from " << s << " to " << h << endl;
        return;
    }

    
    solve(n - 1, s, h, b);   
    cout << "Moving plate " << n << " from " << s << " to " << h << endl;    
    solve(n - 1, b, s, h);
}


int main() {
    int n = 3; 
    solve(n, 'S', 'B', 'D'); 
    return 0;
}