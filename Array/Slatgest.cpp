#include<iostream>
#include<vector>
using namespace std;

int secondlargest(vector<int> &a , int n){
    int largest = a[0];
    int slargest = -1;
    for(int i=1;i<n;i++){
        if(a[i]> largest){
            slargest = largest;
            largest = a[i];
        }
        else if(a[i]< largest && a[i]>slargest){
            slargest = a[i];
        }
    }
    return slargest ;
}

int secondSmallest(vector<int> &a, int n){
    int smallest = a[0];
    int ssmallest = INT_MAX ;
    for(int i=0;i<n;i++){
        if(a[i] < smallest){
            ssmallest = smallest;
            smallest = a[i];
        }
    }
    return ssmallest;
}

vector<int> getSeconglargest(int n , vector<int> a){
    int slargest = secondlargest(a , n);
    int ssmallest = secondSmallest(a , n);
    return {slargest , ssmallest};
}