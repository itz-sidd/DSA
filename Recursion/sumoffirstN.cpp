#include<iostream>
using namespace std;

int sumN(int n){
    if(n==0){
        // return;
        return 0;
    }
    return n + sumN(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<"The sum of first"<< n << "numbers is : " << sumN(n) << endl;
    return 0;
}