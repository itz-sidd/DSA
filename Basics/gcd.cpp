// #include <iostream>
// #include <numeric> // Required for std::gcd in modern C++
// #include <algorithm> // Required for std::min
// #include <vector>

// using namespace std;

// int main() {
//     int n1, n2;
//     cout << "Enter the first number: ";
//     cin >> n1;
//     cout << "Enter the second number: ";
//     cin >> n2;

//     int gcd = 1; // Initialize GCD with 1, as it's the smallest possible GCD

//     // Iterate from 1 up to the minimum of n1 and n2
//     for (int i = 1; i <= min(n1, n2); i++) {
//         // If i divides both n1 and n2 evenly
//         if (n1 % i == 0 && n2 % i == 0) {
//             gcd = i; // Update GCD to the current common divisor
//         }
//     }

//     cout << "The GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

//     return 0;
// }

#include <iostream>
#include <numeric>

class Solution {
  public:
    int gcd(int a, int b) {
    //   cin>>a>>b;
      while (a != b) {
        if (a > b) {
          a = a - b;
        } else {
          b = b - a;
        }
      }
      return a;
    }
};