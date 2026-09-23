#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (char ch = ('A' + n - 1) - i; ch <= 'A' + n - 1; ch++) {
            cout << ch << " ";
        }
        cout << "\n";
    }
    return 0;
}
