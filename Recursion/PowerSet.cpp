#include<iostream>
#include<vector>
#include<string>
using namespace std;

// void subset(string ip , string op){
//     if(ip.length() == 0){
//         cout<< op <<" ";
//         return ;
//     }
//     string op1 = op;
//     string op2 = op;
//     op2.push_back(ip[0]);
//     ip.erase(ip.begin() + 0);
//     subset(ip,op1);
//     subset(ip,op2);
//     return ;
// }

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;  // current subset
        solve(nums, 0, op, ans);
        return ans;
    }

    void solve(vector<int>& nums, int idx, vector<int> op, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(op);
            return;
        }
        vector<int> op1 = op;          // exclude nums[idx]
        vector<int> op2 = op;          // include nums[idx]
        op2.push_back(nums[idx]);

        solve(nums, idx + 1, op1, ans);
        solve(nums, idx + 1, op2, ans);
    }
};