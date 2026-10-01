// Given  an integer n, return the first n (1-Indexed) rows of Pascal's
// triangle.

// In Pascal's triangle:

// The first row has one element with a value of 1.
// Each row has one more element in it than its previous row.
// The value of each element is equal to the sum of the elements directly above
// it when arranged in a triangle format. Example 1: Input: n = 4

// Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]

// Explanation: The Pascal's Triangle is as follows:

// 1

// 1 1

// 1 2 1

// 1 3 3 1

// Approach using the pascal-II and printing every row

#include <iostream>
using namespace std;

void generate(int row) {
    cout << 1 << ' ';
    int res = 1;
    for (int i = 0; i < row; i++) {
        res = res * (row - i);
        res = res / (i + 1);
        cout << res << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        generate(i);
    }
    return 0;
}

// Time complexity: O(N * N)
// Space complexity: O(1)
