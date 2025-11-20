#include<iostream>
#include<map>
#include<vector>
using namespace std;

// string read(int n,vector<int> book,int target){
//     map<int,int>mpp;
//     for(int i=0;i<n;i++){
//         int a=book[i];
//         int more=target-a;
//         if(mpp.find(more)!=mpp.end()){
//             return "Yes";
//         }
//         mpp[a]=i;
//     }
//     return "No";
// }

bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        if(n<2) return false;
        
        int left = 0 , right = n-1;
        
        sort(arr.begin(),arr.end());
        
        while(left<right){
            int sum  = arr[left] + arr[right];
            if(sum == target){
                return true;
            }
            else if(sum<target){
                left++;
            }
            else right--;
        }
        return false;
    }