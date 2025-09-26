#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0; // to count divisors

    if (n <= 1) {
        cout << "False";  // 0 and 1 are not prime
        return 0;
    }

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++; // i is a divisor
            if (i != n / i) {
                cnt++; // n/i is another divisor (avoid double count for perfect squares)
            }
        }
    }

    if (cnt == 2) {
        cout << "True";  // only 1 and n are divisors
    } else {
        cout << "False";
    }

    return 0;
}
