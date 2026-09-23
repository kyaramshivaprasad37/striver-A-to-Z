// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         char ch = 'A';
//         for (int j = 0; j <= i; j++) {
//             cout << static_cast<char>(ch + i) << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    char ch = 'A';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ch << " ";
        }
        ch += 1;
        cout << "\n";
    }
    return 0;
}
