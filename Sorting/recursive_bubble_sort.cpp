#include <iostream>
#include <vector>
using namespace std;

void bubble(vector<int> &a, int n) {
    if (n == 0) {
        return;
    }
    int swapped = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            swapped = 1;
        }
    }
    if (swapped = 0) {
        return;
    }
    bubble(a, n - 1);
}

int main() {
    vector<int> arr{4, 3, 5, 72, 3, 5};
    bubble(arr, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}
