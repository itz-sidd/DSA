#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums, int index, int sum, int& count, int& target){
    if(index == nums.size()){
        if(sum == target){
            count++;
        }
        return;
    }

    solve(nums, index+1, sum+nums[index], count, target);

    solve(nums, index+1, sum, count, target);
}

int subsequencewithsumk(vector<int> nums, int target){
    int count = 0;
    solve(nums, 0, 0, count, target);
    return count;
}


int main() {
    vector<int> nums = {1, 1, 1, 2, 3, 4, 5};
    int target = 2;

    cout << subsequencewithsumk(nums, target) << "\n"; 

    return 0;
}

