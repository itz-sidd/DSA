#include<iostream>
#include<vector>
using namespace std;

void sortarr(vector<int>& nums){
    int n = nums.size();
    int low=0;
    int mid = 0;
    int high = n-1;

    while(mid<=high){
        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[high],nums[mid]);
            high--;
        }
    }
}

int main(){
    int n;
    if(cin>>n){
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            cout<<endl;
        }
        sortarr(nums);
        for(int i=0;i<n;i++){
            cout<<nums[i];
        }
    }
    return 0;
}