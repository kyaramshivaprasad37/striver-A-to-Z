#include <iostream>
#include <math.h>
using namespace std;
int digits(int x) {
    int count = 0;
    while (x != 0) {
        x = x / 10;
        count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int digit{digits(n)};
    int sum{0};
    int temp = n;
    while (temp != 0) {
        int rem = temp % 10;
        sum = sum + (pow(rem, digit));
        temp = temp / 10;
    }
    cout << sum << "\n";

    if (sum == n) {
        cout << "True" << "\n";
    } else {
        cout << "False" << "\n";
    }

    return 0;
}
