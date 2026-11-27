// 78. Subsets

// Given an integer array nums of unique elements, return all possible subsets
// (the power set).

// The solution set must not contain duplicate subsets. Return the solution in
// any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Approach : using Recursion on subsequence

// code_start

class Solution {
  public:
    void backtrack(vector<int> &nums, vector<int> temp,
                   vector<vector<int>> &res, int i) {
        if (i == nums.size()) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        backtrack(nums, temp, res, i + 1);
        temp.pop_back();
        backtrack(nums, temp, res, i + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(nums, temp, res, 0);
        return res;
    }
};

// code_end

// Time Complexity : O(2^n)
// Space Complexity : O(n^2)
