#include <iostream>
using namespace std;

int main() {
    int a[] = {3, 5, 6, 7, 2};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n - 1; i++) {
        int small = i;
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                small = j;
            }
        }
        int temp = a[small];
        a[small] = a[i];
        a[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
