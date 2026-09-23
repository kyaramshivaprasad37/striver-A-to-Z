#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        } else {
            temp.push_back(a[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(a[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
}

void divide(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    divide(arr, low, mid);
    divide(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    vector<int> a = {3, 4, 6, 1, 5};
    divide(a, 0, a.size() - 1);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
