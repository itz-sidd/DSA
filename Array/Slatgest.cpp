#include<iostream>
#include<vector>
using namespace std;

int secondlargest(vector<int>& nums, int n){

    if(n<2) return -1;
    int largest = nums[0];
    int slargest;

    for(int i=1;i<n;i++){
        if(nums[i] > largest){
            slargest = largest;
            largest = nums[i];
        }
        else if(nums[i] > slargest && largest != nums[i]){
            slargest = nums[i];
        }
    }
    return slargest;
}

int main(){
    int n;
    if(cin>>n){
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans = secondlargest(arr,n);

        cout<<ans<<endl;
    }
    return 0;
}