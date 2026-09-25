// Given an m x n matrix, return all elements of the matrix in spiral order.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Approach
// Take pointer for right = m-1, left = 0; bottom = n-1; top = 0
// while through top <= bottom and left <= right
// take for loop for printing loop with incrementing and decrementing
// correponding values

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int left = 0;
        int right = m - 1;
        int bottom = n - 1;
        vector<int> Arr;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                Arr.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                Arr.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    Arr.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    Arr.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return Arr;
    }
};

// Time complexity --- O(n x m)
// Space complexity --- O(n x m)
