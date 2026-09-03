#include<iostream>
#include<vector>
using namespace std;

int cntone(vector<int> &nums,int k){
    int n = nums.size();
    int zerocnt = 0;
    int maxones = 0;
    int left = 0;

    for(int i=0;i<n;i++){
        if(nums[i] == 0){
            zerocnt++;
        }
        while(zerocnt>k){
            if(nums[left] == 0){
                zerocnt--;
            }
            left++;
        }
        maxones = max(maxones,i-left+1);
    }

    return maxones;

}

int main(){
    int n;
    int k = 2;
    vector<int>nums = {1,1,0,0,1,1,1,1,1,0};

    cout<<cntone(nums,k);
}