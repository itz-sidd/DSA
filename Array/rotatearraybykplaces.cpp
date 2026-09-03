#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& nums, int low, int high){
    int n = nums.size();

    while(low<high){
        swap(nums[low],nums[high]);
        low++;
        high--;
    }
}

void reversekplaces(vector<int>& nums, int k){
    int n = nums.size();
    if(n  == 0) return;
    if(k==0) return;
    k = k%n;
    

    reverse(nums,0,n-1);
    reverse(nums,0,k-1);
    reverse(nums,k,n-1);
}

int main(){
    int n;
    int k;
    cout<<"Enter k :"<<endl;
    cin>>k;
    if(cin>>n){
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            cout<<endl;
        }

        reversekplaces(nums,k);

        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
    }
    return 0;
}