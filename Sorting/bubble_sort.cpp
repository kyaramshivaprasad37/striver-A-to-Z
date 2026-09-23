#include <iostream>
using namespace std;

int main() {
    int a[] = {2, 6, 2, 35, 8};
    int l = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < l - 1; i++) {
        bool sorted = true;
        for (int j = 0; j < l - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sorted = false;
            }
        }
        if (sorted) {
            break;
        }
    }

    for (int i = 0; i < l; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
