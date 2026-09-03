#include<iostream>
#include<vector>
using namespace std;

vector<int> prefmax(vector<int>&nums,int n){
    vector<int>pref(n);
    pref[0] = nums[0];

    for(int i=1;i<n;i++){
        pref[i] = max(pref[i-1],pref[i]);
    }
    return pref;
}

vector<int> suffmax(vector<int>&nums,int n){
    vector<int>suff(n);

    suff[n-1] = suff[n-1];

    for(int i=n-2;i>=0;i--){
        suff[i] = max(suff[i],suff[i+1]);
    }
    return suff;
}

int main(){
    
    vector<int> arr = {1, 3, 4, 5, 6, 7, 8, 9, 10, 122};
    
    
    int n = arr.size(); 

    
    vector<int> pref = prefmax(arr, n);
    vector<int> suff = suffmax(arr, n);

    
    cout << "Prefix Max array: ";
    for(int i = 0; i < n; i++){
        cout << pref[i] << " ";
    }
    cout << endl;

    cout << "Suffix Max array: ";
    for(int i = 0; i < n; i++){
        cout << suff[i] << " ";
    }
    cout << endl;

    return 0;
}