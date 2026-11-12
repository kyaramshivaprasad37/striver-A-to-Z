

// code_start

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = row - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int first = matrix[mid][0];
            int last = matrix[mid][col - 1];
            if (first <= target && last >= target) {
                int low1 = 0;
                int high1 = col - 1;
                while (low1 <= high1) {
                    int mid1 = low1 + (high1 - low1) / 2;
                    if (matrix[mid][mid1] == target) {
                        return true;
                    } else if (matrix[mid][mid1] > target) {
                        high1 = mid1 - 1;
                    } else {
                        low1 = mid1 + 1;
                    }
                }
                return false;
            } else if (last < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};

// code_end
