// Given an integer r, return all the values in the rth row (1-indexed) in
// Pascal's Triangle in correct order.

// In Pascal's triangle:

// The first row has one element with a value of 1.
// Each row has one more element in it than its previous row.
// The value of each element is equal to the sum of the elements directly above
// it when arranged in a triangle format. Example 1: Input: r = 4

// Output: [1, 3, 3, 1]

// Approach: using nCr for the whole row and printing elements

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     n = n - 1;
//     int r = 0;
//     while (r <= n) {
//         int res = 1;
//         for (int i = 0; i < r; i++) {
//             res = res * (n - i);
//             res = res / (i + 1);
//         }
//         cout << res << ' ';
//         r++;
//     }
//     return 0;
// }

// Time complexity: O(n x n)
// Space complexity O(1) or O(n) if array is used to store elements

//**** optimal Approach ****/
// taking ans as 1 i.e first element then multipying current row and divide by
// col by zero index until the last column

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    n = n - 1;
    int res = 1;
    cout << res << ' ';
    for (int i = 0; i < n; i++) {
        res = res * (n - i);
        res = res / (i + 1);
        cout << res << ' ';
    }
    return 0;
}

// Time Complexity: O(N)
// Space complexity: O(1)
