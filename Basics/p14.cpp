#include <iostream>
using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     char alp{65};

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j <= i; j++) {
//             cout << static_cast<char>(alp + j);
//         }
//         cout << "\n";
//     }

//     return 0;

//}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (char ch = 'A'; ch <= 'A' + i; ch++) {
            cout << ch << " ";
        }
        cout << "\n";
    }
    return 0;
}
