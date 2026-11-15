#include <bits/stdc++.h>
// A peak element in a 2D grid is an element that is strictly greater than all
// of its adjacent neighbors to the left, right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal,
// find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter
// with the value - 1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

// Example 1:

// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both
// acceptable answers.

// Example 2:

// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both
// acceptable answers.

//***/Brute Force ***
// Approach : checking left right top and bottom for every element till
// condition is true

// class Solution {
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int row = mat.size();
//         int col = mat[0].size();
//         for(int i = 0; i < row;i++) {
//             for(int j = 0; j < col; j++) {
//                 int left = -1;
//                 int right = -1;
//                 int top = -1;
//                 int bottom = -1;
//                 if(i > 0) {
//                     top = mat[i-1][j];
//                 }
//                 if(i < row -1) {
//                     bottom = mat[i+1][j];
//                 }
//                 if(j > 0) {
//                     left = mat[i][j-1];
//                 }
//                 if(j < col-1) {
//                     right = mat[i][j+1];
//                 }
//                 if(mat[i][j] >= left && mat[i][j] >= right && mat[i][j] >=
//                 top && mat[i][j] >= bottom) {
//                     return {i,j};
//                 }
//             }
//         }
//         return {-1,-1};
//     }
// };

// Time Complexity: O(n x m)
// Space complexity; O(1)

// *** Optimal Approach ***
// Approach : we are using the same concept as find peak element - I
//           1. first we are using cols as boundaries i.e low = 0 and high =
//           col-1
//           2. then we find middle col
//           3. then int that middle column we find max value
//           4. by finding max value we dont need to check for top and bottom
//           since its the max element in that column
//           5. then we check for its right and left and follow the same concept
//           as old problems for
//           6. eliminating right and left part of matrix

// code_start

class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();
        int low = 0;
        int high = col - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxIndex = -1;
            int max = INT_MIN;
            for (int i = 0; i < row; i++) {
                if (mat[i][mid] > max) {
                    max = mat[i][mid];
                    maxIndex = i;
                }
            }
            int left = (mid - 1 >= 0) ? mat[maxIndex][mid - 1] : -1;
            int right = (mid + 1 <= col - 1) ? mat[maxIndex][mid + 1] : -1;
            if (left < mat[maxIndex][mid] && mat[maxIndex][mid] > right) {
                return {maxIndex, mid};
            }
            if (left > mat[maxIndex][mid]) {
                high = mid - 1;
            } else if (right > mat[maxIndex][mid]) {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};

// code_end
// Time Complexity : O(log(m) x n) m->column , n-> row
// Space Complexity: O(1)
