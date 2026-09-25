// Print the element of nth column rth row of Pascals triangle
//        1
//      1   1
//    1   2   1
//  1   3   3    1

// Approach
// Formula for this is n-1Cr-1;

#include <iostream>
using namespace std;

int main() {
    int n;
    int r;
    cin >> n >> r;
    int res = 1;
    n = n - 1;
    r = r - 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    cout << res;
    return 0;
}

// Time complexity ---- O(r)
// Space complexity --- S(1)
