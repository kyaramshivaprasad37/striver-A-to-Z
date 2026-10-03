// Given an m x n integer matrix matrix, if an element is 0, set its entire row
// and column to 0. You must do it in place.

// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]

// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Explanation:

// Element at position (1,1) is 0, so set entire row 1 and column 1 to 0.

// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// ** Better **
// Approach: First we take two arrays of size n and m and initialize to 0
//           in first iteration if we find a element 0 element then we mark the
//           col and row element of that array to 1 then in the next iteation by
//           checking each element if the array has 1 for either row or col then
//           we set that to 0

#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int matrix[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    int row[r]{};
    int col[c]{};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

// Time Complexity: O(r*c + r*c)
// Space complexity: O(r+c);

// *** Optimal Approach ***
//
// Approach: Record whether the first row or first column originally contains
// zero. Inspect only the inner matrix cells and use the first cell of the same
// row and same column as zero markers. Inspect the inner matrix cells again and
// set a cell to zero when its row marker or column marker is zero. Clear the
// first row when it originally contained zero, and clear the first column when
// it originally contained zero. The process terminates after these marker
// applications, and only constant extra variables are used.

class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        int col0 = 1;
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

// Time complexity: O(2 x r x c)
// Space complexity : O(1)
