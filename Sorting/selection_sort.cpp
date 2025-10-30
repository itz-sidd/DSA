// #include<iostream>
// using namespace std;

// void selectionsort(int arr[],int n){
//     for(int i=0;i<=n-2;i++){
//         int mini=i;
//         for(int j=i+1;j<=n-1;j++){
//             if(arr[j]<arr[mini]){
//                 mini=j;
//             }
//         }
//         int temp=arr[mini];
//         arr[mini]=arr[i];
//         arr[i]=temp;
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         selectionsort(arr,n);
//         for(int i=0;i<n;i++){
//             cout<<arr[i]<< " ";
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>  // for std::swap
using namespace std;

void selectionsort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= n - 2; i++) {
        int mini = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        std::swap(arr[i], arr[mini]);  // explicit std:: to avoid ambiguity
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionsort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}