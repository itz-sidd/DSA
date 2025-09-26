#include<iostream>
using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }
    int last=fib(n-1);
    int slast=fib(n-2);
    int current;

    current=last+slast;
    slast=last;
    last=current;

    return current;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}