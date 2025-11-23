#include<iostream>
#include<vector>
using namespace std;

vector<int> alternateNumbers(vector<int> &a){
    vector<int> pos, neg;
    int n = a.size();

    for(int i=0;i<n;i++){
        if(a[i] > 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }

    int i = 0, j = 0, k = 0;

    while(i < pos.size() && j < neg.size()){
        a[k++] = pos[i++];
        a[k++] = neg[j++];
    }

    while(i < pos.size()) a[k++] = pos[i++];
    while(j < neg.size()) a[k++] = neg[j++];

    return a;
}
