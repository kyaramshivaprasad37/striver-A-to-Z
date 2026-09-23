// #include <iostream>
// using namespace std;

// int gcd(int x, int y) {
//     if (y == 0) {
//         return x;
//     }
//     return gcd(y, x % y);
// }

// int main() {
//     int x, y;
//     cin >> x >> y;
//     cout << gcd(x, y) << "\n";
//     return 0;
// }

#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    int temp;
    while (y != 0) {
        temp = y;
        y = x % y;
        x = temp;
    }
    cout << temp << "\n";

    return 0;
}
