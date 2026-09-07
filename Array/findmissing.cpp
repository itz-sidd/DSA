#include<iostream>
#include<vector>
using namespace std;

int findmissing(vector<int>& nums){
    int n = nums.size()+1;
    int sum = (n*(n+1))/2;
    int s = 0;

    for(int x : nums){
        s+=x;
    }
    return (sum-s);
}

int main(){
    
    vector<int> nums = {1,2,3,5};

    cout<<findmissing(nums);
}