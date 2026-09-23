#include <iostream>
#include <vector>
using namespace std;

void fun(vector<int> &a, int n, int i) {
    if (i == n) {
        return;
    }
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
    return fun(a, n, i + 1);
}

int main() {
    vector<int> a{3, 5, 2, 1, 5, 6};
    int n = a.size();
    fun(a, n, 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
