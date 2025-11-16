#include<iostream>
#include<vector>
using namespace std;

// void leftRotate(int arr[],int n,int d){
//     d = d%n;

//     int temp[d];
//     for(int i=0;i<d;i++){
//         temp[i] = arr[i];
//     }
//     for(int i=d;i<n;i++){
//         arr[i-d] = arr[i];
//     }
//     for(int i=n-d;i<n;i++){
//         arr[i] = temp[i - (n-d)];
//     }
// }

void reverse(int arr[],int start,int end){
    while(start<end){
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start ++;
        end --;
    }
}

void leftrotate(int arr[],int n,int d){
     reverse(arr, 0, d - 1);       // reverse first d elements
    reverse(arr, d, n - 1);       // reverse remaining
    reverse(arr, 0, n - 1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n); 
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int d;
    cin >> d;
    leftrotate(arr.data(), n, d);
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    return 0;
}