#include<iostream>
#include<vector>
using namespace std;

int findlargest(vector<int>& arr,int n){
    int largest = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

int main(){
    int n;
    
    if(cin>>n){
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans = findlargest(arr,n);
        cout<<ans<<endl;
        
    }
    return 0;
}
