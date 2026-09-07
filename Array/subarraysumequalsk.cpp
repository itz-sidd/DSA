#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int subarrsumk(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int,int>mpp;
    int sum = 0;
    int longest = 0;

    for(int i=0;i<n;i++){
        sum+=nums[i];

        if(sum == k){
            longest = max(longest,i+1);
        }
        
        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            longest = max(longest,len);
        }
        if(mpp.find(sum) == mpp.end()) mpp[sum] = i;
        
    }
    return longest;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << subarrsumk(nums, k) << "\n";

    return 0;
}