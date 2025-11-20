#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// void revArr(vector<int>& arr, int l, int r) {
//     if (l >= r) {
//         return;
//     }
//     swap(arr[l], arr[r]);
//     revArr(arr, l + 1, r - 1);
// }

// int main() {
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;

//     if (n <= 0) {
//         cout << "Invalid array size." << endl;
//         return 0;
//     }

//     vector<int> arr(n);
//     cout << "Enter " << n << " integers, separated by spaces: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     cout << "Original array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     revArr(arr, 0, n - 1);

//     cout << "Reversed array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

