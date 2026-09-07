#include <iostream>
#include <vector>
using namespace std;

void generatesets(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans){
    if(index == nums.size()){
        ans.push_back(path);
        return;
    }

    path.push_back(nums[index]);
    generatesets(index+1,nums,path,ans);

    path.pop_back();
    generatesets(index+1,nums,path,ans);

}

vector<vector<int>> powerset(vector<int> nums){
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> path;

    generatesets(0,nums,path,ans);

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = powerset(nums);

    for (const auto& subset : result) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}