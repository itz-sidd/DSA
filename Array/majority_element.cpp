#include <vector>
#include<iostream>
#include <map>

using namespace std;


int majorityelement(vector<int>& nums){
    int n = nums.size();

    int candidate = 0;
    int cnt = 0;

    for(int i=0;i<n;i++){
        if(cnt == 0) candidate = nums[i];

        if(nums[i] == candidate) cnt++;
        else cnt--;
    }

    int verify_cnt = 0;
    for(int i=0;i<n;i++){
        if(candidate == nums[i]) verify_cnt++;
        
    }
    if(cnt> (n/2)) return candidate;
    return -1;
}

int main() {
    int n;
    
    cout << "Enter array size: ";
    if (cin >> n) {
        vector<int> nums(n);
        
        cout << "Enter the numbers: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        int ans = majorityelement(nums);
        
        if (ans != -1) {
            cout << "Majority element: " << ans << "\n";
        } else {
            cout << "No majority element found.\n";
        }
    }
    
    return 0;
}