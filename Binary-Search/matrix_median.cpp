// Given a row-wise sorted matrix mat[][], where the number of rows and columns
// is always odd. Return the median of the matrix.

// Examples:

// Input: mat[][] = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9].
// Hence, 5 is median. Input: mat[][] = [[2, 4, 9], [3, 6, 7], [4, 7, 10]]
// Output: 6
// Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10].
// Hence, 6 is median.

// *** Brute Force ***
// Approach : copying all elements from array to a new temp array, sorting that
// temp array and
//            returning median

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        vector<int> temp;
        int row = mat.size();
        int col = mat[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp.push_back(mat[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        int n = temp.size();
        return temp[n / 2];
    }
};

// Time Complexity: O(n x m + zlog(z)) z = nxm
// Space Complexity : O(n x m)

//*** Optimal Approach ***/
// Approach : in notes
class Solution {
  public:
    int upperBound(vector<int> &row, int x) {
        int low = 0;
        int high = row.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    int countSmallEqual(vector<vector<int>> &mat, int x) {
        int cnt = 0;
        for (int i = 0; i < mat.size(); i++) {
            cnt += upperBound(mat[i], x);
        }
        return cnt;
    }

    int median(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        int req = (row * col) / 2;
        for (int i = 0; i < row; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][col - 1]);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int smallEqual = countSmallEqual(mat, mid);
            if (smallEqual <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

// Time complexity : O(log(10**9)) x n x log(m)
// Space complexity : O(1)
