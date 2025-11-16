// #include<iostream>
// #include<vector>
// using namespace std;

// void insert(vector<int> & v, int temp){
//     if(v.size==0 || v[v.size()-1]<=temp){
//         v.push_back(temp);
//     }
//     int val = v[v.size()-1];
//     v.pop_back();
//     insert(v,temp);
//     v.push_back(val);
// }

// void sort(vector<int> & v){
//     if(vector.size()==1){
//         return ;
//     }
//     int temp = v[v.size()-1];
//     v.pop_back();
//     sort(v);
//     insert(v,temp);
// }
#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& v, int temp) {
    // Base case: if vector is empty or last element <= temp, insert temp
    if (v.size() == 0 || v.back() <= temp) {
        v.push_back(temp);
        return;
    }

    
    int val = v.back();
    v.pop_back();
    insert(v, temp);     
    v.push_back(val);    
}

void sort(vector<int>& v) {
    // Base case: if only one element, it's sorted
    if (v.size() == 1) {
        return;
    }

    int temp = v.back();
    v.pop_back();
    sort(v);             
    insert(v, temp);     
}


int main() {
    vector<int> v = {5, 2, 4, 1, 3};
    sort(v);
    for (int x : v) {
        cout << x << " ";
    }
    return 0;
}