#include<iostream>
#include<vector>
using namespace std;


int maxsubarrsum(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    int maximumsum = INT_MIN;

    for(int i=0;i<n;i++){
        sum+=nums[i];
        maximumsum = max(maximumsum,sum);

        if(sum<0){
            sum = 0;
        }
    }
    return maximumsum;
}