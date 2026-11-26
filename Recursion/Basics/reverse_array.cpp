#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int left, int right) {
    if (left >= right) {
        return;
    }
    swap(arr[left], arr[right]);
    reverse(arr, left + 1, right - 1);
}

int main() {
    vector<int> arr = {10, 40, 50, 30, 78, 69, 37};
    int n = arr.size();
    reverse(arr, 0, n - 1);
    for (auto i : arr) {
        cout << i << ' ';
    }
    return 0;
}
