// 765. Find out how many times the array is rotated
// Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.

// Example 1:
// Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

// Output: 4

// Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

// Example 2:
// Input: nums = [3, 4, 5, 1, 2]

// Output: 3


// *** optimal Approach ***
// Approach: using finding the minimum element usign binary search and updting index

class Solution {
   public:
    int findKRotation(vector<int> &nums) {
        int low = 0;
        int high = (int)nums.size() - 1;
        int ans = INT_MAX;
        int index;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (nums[low] <= nums[middle]) {
                if(nums[low] <= ans) {
                    ans = nums[low];
                    index = low;
                }
                low = middle + 1;
            } else {
                if(nums[middle] <= ans) {
                    ans = nums[middle];
                    index = middle;
                }
                high = middle - 1;
            }
        }
        return index;
    }
};

// Time Complexity: O(log(N))
// Space conplexity: O(1)
