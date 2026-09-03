#include<iostream>
#include<vector>
using namespace std;

int trappingrainwater(vector<int>&heights){
    int n = heights.size();
    int left = 0;
    int right = n-1;
    int ans = 0;
    int lmax = 0;
    int rmax = 0;

    while(left<right){
        if(heights[left]<=heights[right]){
            if(heights[left]>=lmax){
                lmax = heights[left];
            }
            else{
                ans+=lmax - heights[left];
            }
            left++;
        }
        else{
            if(heights[right]>=rmax){
                rmax = heights[right];
            }
            else{
                ans+=rmax-heights[right];
            }
            right--;
        }
    }
    return ans;

}

int main(){
    int n;
    cout<<endl;
    if(cin>>n){
        vector<int>nums(n);
        cout<<"Enter array"<<endl;
        for(int i=0;i<n;i++){
            
            cin>>nums[i];
        }
        int result = trappingrainwater(nums);
        cout<<endl;

        cout<<result;
    }
}