#include<iostream>
#include<vector>
using namespace std;

int leftrotate(vector<int> &arr,int n){
    int temp = arr[0];
    for(int i=0;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}