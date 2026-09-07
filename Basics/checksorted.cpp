#include<iostream>
#include<vector>
using namespace std;

bool checksortedarray(vector<int>& nums){
    int n = nums.size();
    int count = 0;
    for(int i=0;i<n;i++){
        if(nums[i] > nums[(i+1 % n)]) count++;
         
    }
    if(count > 1) return false;

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (checksortedarray(nums)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}