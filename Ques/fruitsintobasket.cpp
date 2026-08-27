#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int fruitsintobasket(vector<int> &nums){
    int n = nums.size();
    unordered_map<int,int>freq;
    int left = 0;
    int maxlen = 0;

    for(int right = 0;right<n;right++){
        freq[nums[right]]++;

        while(freq.size() > 2){
            freq[nums[left]]--;
            if(freq[nums[left]] == 0){
                freq.erase(nums[left]);
            }
            left++;
        }
        maxlen = max(maxlen,right-left+1);
    }
    return maxlen;
}

int main(){
    int n;
    if(cin>>n){
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cout<<"Enter numbers:"<<"\n";
            cin>>nums[i];
        }
        cout<<fruitsintobasket(nums)<<" ";

        for(int k=0;k<n;k++){
        cout<<nums[k];
        }
    }
    return 0;
}
