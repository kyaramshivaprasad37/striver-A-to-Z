// #include <iostream>
// #include <set>
// using namespace std;

// int main() {
//     int a1[] = {1, 2, 4, 6, 7, 7, 9};
//     int a2[] = {3, 4, 5, 5, 7, 9};
//     int l1 = sizeof(a1) / sizeof(a1[0]);
//     int l2 = sizeof(a2) / sizeof(a2[0]);

//     set<int> s;

//     for (int i = 0; i < l1; i++) {
//         s.insert(a1[i]);
//     }
//     for (int i = 0; i < l2; i++) {
//         s.insert(a2[i]);
//     }

//     int l3 = s.size();
//     int a3[l3];
//     int j = 0;
//     for (auto i : s) {
//         a3[j++] = i;
//     }
//     for (int i = 0; i < l3; i++) {
//         cout << a3[i] << ' ';
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 4, 6, 7, 7, 9};
    int b[] = {3, 4, 5, 5, 7, 9};

    int l1 = sizeof(a) / sizeof(a[0]);
    int l2 = sizeof(b) / sizeof(b[0]);

    int c[l1 + l2];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < l1 && j < l2) {
        if (a[i] < b[j]) {
            if (k == 0 || c[k - 1] != a[i]) {
                c[k++] = a[i];
            }
            i++;
        } else {
            if (k == 0 || c[k - 1] != b[j]) {
                c[k++] = b[j];
            }
            j++;
        }
    }
    while (i < l2) {
        if (c[k - 1] != a[i]) {
            c[k++] = a[i];
        }
        i++;
    }
    while (i < l2) {
        if (c[k - 1] != b[j]) {
            c[k++] = b[j];
        }
        j++;
    }
    for (int i = 0; i < k; i++) {
        cout << c[i] << ' ';
    }
    return 0;
}
