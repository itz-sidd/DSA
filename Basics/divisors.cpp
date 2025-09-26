#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << " ";       // print divisor
            if (i != n / i) {
                cout << n / i << " ";  // print pair divisor
            }
        }
    }
    return 0;
}
