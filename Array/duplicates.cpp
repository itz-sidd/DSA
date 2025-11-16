#include <iostream>
#include <set>
#include<vector>
using namespace std;


// int removeDuplicates(int arr[], int n) {
//     set<int> st;
//     for (int i = 0; i < n; i++) {
//         st.insert(arr[i]);
//     }

//     int index = 0;
//     for (int x : st) {
//         arr[index] = x;
//         index++;
//     }

//     return index; 
// }

// int main() {
//     int arr[] = {3, 1, 2, 2, 3, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int newSize = removeDuplicates(arr, n);

//     cout << "Unique elements: ";
//     for (int i = 0; i < newSize; i++) {
//         cout << arr[i] << " ";
//     }
//     // Output: 1 2 3 4

//     return 0;
// }

int removeDuplicates(vector<int> &arr, int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}