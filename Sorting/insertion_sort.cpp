#include <iostream>
using namespace std;

int main() {
    int a[] = {6, 4, 3, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 1; i < n; i++) {
        int m = a[i];
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (a[j] > m) {
                a[j + 1] = a[j];
            } else {
                break;
            }
        }
        a[j + 1] = m;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
