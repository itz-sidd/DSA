#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> twosum(vector<int>& nums, int target){
    int n = nums.size();
    unordered_map<int,int>mpp;

    for(int i=0;i<n;i++){
        int rem = target - nums[i];

        if(mpp.find(rem) != mpp.end()){
            return {mpp[rem], i};
        }
        mpp[nums[i]] = i;
    }
    return {-1,-1};
}

int main(){
    int n;
    int target;
    cout<<"enter target:"<<endl;
    cin>>target;

     if(cin>>n){
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            cout<<endl;
        }
        vector<int> ans = twosum(nums,target);
        if (ans[0] != -1) {
            cout << "Indices found: [" << ans[0] << ", " << ans[1] << "]" << endl;
        }
    }
    return 0;
}