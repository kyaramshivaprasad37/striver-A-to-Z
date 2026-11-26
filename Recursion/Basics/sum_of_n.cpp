#include <iostream>
using namespace std;

void parameterized(int n, int sum) {
    if (n < 0) {
        cout << sum << '\n';
        return;
    }
    parameterized(n - 1, sum + n);
}

int functional(int n) {
    if (n == 0) {
        return 0;
    }
    return n + functional(n - 1);
}

int main() {
    // parameterized(3, 0);
    cout << functional(3) << '\n';
    return 0;
}
