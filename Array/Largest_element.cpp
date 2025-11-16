#include<iostream>
#include<vector>
using namespace std;

int largest_element(vector<int> &arr, int n){
    int largest =arr[0];
    for(int i = 1 ; i<n ; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    cout<<largest;
}