#include <iostream>
using namespace std;

void printnum(int n) {
    // cin>>n;
    if (n == 0) {
        return;
    }
    printnum(n - 1);
    cout << n << " ";
}

int main() {
    int n;
    cin>>n; 
    printnum(n);
    cout << endl;
    return 0;
}