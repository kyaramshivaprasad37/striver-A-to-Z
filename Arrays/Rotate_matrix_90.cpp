// Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.

// The rotation must be done in place, meaning the input 2D matrix must be
// modified directly.

// Example 1:
// Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

// Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

// Approach: changing elements of rows to cols from last

class Solution {
  public:
    void rotateMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> temp(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp[j][col - i - 1] = matrix[i][j];
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = temp[i][j] << ' ';
            }
        }
    }
};

// Time complexity: O(r x c)
// Space complexity: O(r x c)
