#include "iostream"
using namespace std;

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << j + 1;
        }

        for (int j = 0; j <= (n * 2 - 2) - 2 * i; j++) {
            cout << " ";
        }

        for (int k = i + 1; k > 0; k--) {
            cout << k;
        }

        cout << "\n";
    }
    return 0;
}
