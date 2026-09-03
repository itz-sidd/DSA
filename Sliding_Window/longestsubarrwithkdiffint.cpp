#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

  
  int subarrays(vector<int>& nums,int k){
        int n = nums.size();
        unordered_map<int,int>freq;
        int cnt = 0;

        int left = 0;
        int maxlen = 0;

        for(int right = 0;right < n; right++){
            freq[nums[right]]++;

            while(freq.size() > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            cnt+= (right-left+1);
        }
        return cnt;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       if(nums.size() == 0) return 0;
       if(nums.size()<k) return 0;

       return subarrays(nums,k) - subarrays(nums,k-1);
    }

int main(){
    int n;
    int k;
    cout<<"Enter n:"<<endl;
    cin>>n;

    cout<<"Enter k :"<<endl;
    cin>>k;

    vector<int> nums(n);
    
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<subarraysWithKDistinct(nums,k)<<endl;
    
    
    // vector<int>nums = {12,3,4,5,1,2,3,4,5};

    // cout<<subarraysWithKDistinct(nums,k)<<" ";


}