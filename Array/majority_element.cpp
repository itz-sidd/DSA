#include <vector>
#include <map>

using namespace std;


// vector<int> majorityElement(vector<int> v) {
//     map<int, int> mpp;
//     int n = v.size();

//     for (int i = 0; i < n; i++) {
//         mpp[v[i]]++;
//     }

//     for (auto it : mpp) {
//         if (it.second > (n / 2)) {
            
//             return {it.first};
//         }
//     }
    
//     // Return an empty vector if no majority element is found
//     return {}; 
// }
int majorityElement(vector<int>& nums) {
        int cnt=0;
        int el;
        for(int i=0;i<nums.size();i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el){
                cnt++;
            }
            else {cnt--;}
        }
        int cnt1 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == el){
                cnt1++;
            }
            if(cnt1>(nums.size()/2)){
                return el;
            }
        }
         