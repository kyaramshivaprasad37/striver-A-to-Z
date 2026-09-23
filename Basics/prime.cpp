#include <iostream>
#include <math.h>
using namespace std;
int main() {
    bool isPrime{true};
    int n;
    cin >> n;
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = false;
        }
    }
    if (isPrime) {
        cout << "Prime" << "\n";
    } else {
        cout << "Not Prime" << "\n";
    }
    return 0;
}
