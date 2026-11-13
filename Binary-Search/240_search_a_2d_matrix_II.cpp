// Write an efficient algorithm that searches for a value target in an m x n
// integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Example 1:

// Input: matrix =
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
// target = 5 Output: true Example 2:

// Input: matrix =
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
// target = 20 Output: false

// Better Approach
// Approach : 1. treating each row as individual array and applying binary
// search on each

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        int row = mat.size();
        int col = mat[0].size();
        for (int i = 0; i < row; i++) {
            int low = 0;
            int high = col - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (mat[i][mid] == target) {
                    return true;
                } else if (mat[i][mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};

// Time Complexity: (n x log(m))
// Space Complexity: O(1)

//*** Optimal Approach ***
// Approach : If we observe the matrix the at last element of 1st row i.e
// mat[0][col-1] we can observe that all elements left to that in that row are
// smaller and
//           all elements below that element in same col are greater so
//           we can check from mat[0][col-1]
//           if(target < mat[i][j])  j--    (i = 0, j = col-1)
//           else i++

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        int row = mat.size();
        int col = mat[0].size();
        int i = 0;
        int j = col - 1;
        while (i < row && j >= 0) {
            if (mat[i][j] == target) {
                return true;
            }
            if (target < mat[i][j]) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

// Time complexity : (n + m)
// Space complexity : (1)
