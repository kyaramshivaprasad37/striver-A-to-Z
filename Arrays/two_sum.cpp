#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 6};
    int target = 100;
    int n = sizeof(a) / sizeof(a[0]);
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int m = a[i];
        int rem = target - m;
        if (mpp.find(rem) != mpp.end()) {
            cout << "YES" << '\n';
            return 0;
        }
        mpp[m] = i;
    }
    cout << "NO" << '\n';
    return 0;
}
