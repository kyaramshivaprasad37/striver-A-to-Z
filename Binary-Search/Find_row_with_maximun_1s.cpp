// 707. Find row with maximum 1's
// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows
// are sorted in ascending order, find the index of the row with the maximum
// number of ones.

// If two rows have the same number of ones, consider the one with a smaller
// index. If no 1 exists in the matrix, return -1.

// Example 1:
// Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]

// Output: 0

// Explanation: The row with the maximum number of ones is 0 (0 - indexed).

// Example 2:
// Input: mat = [ [0, 0], [0, 0] ]

// Output: -1

// Explanation: The matrix does not contain any 1. So, -1 is the answer.

// Optimal Approach
// Approach: using for loop to loop row
//           and using binary search to find 1 then cnt = col - mid -1

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();
        int index = -1;
        int cnt = -1;
        for (int i = 0; i < row; i++) {
            int low = 0;
            int high = col;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (mat[i][mid] == 1) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (mat[i][low] == 1) {
                if (cnt < col - low - 1) {
                    cnt = col - low - 1;
                    index = i;
                }
            }
        }
        return index;
    }
};

// Time Complexity : O(nlog(m))
// Space complexity : O(1)
