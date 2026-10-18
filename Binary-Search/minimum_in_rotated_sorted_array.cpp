// 62. Find minimum in Rotated Sorted Array
// Given an integer array nums of size N, sorted in ascending order with distinct values, and then rotated an unknown number of times (between 1 and N), find the minimum element in the array.

// Example 1:
// Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

// Output: 0

// Explanation: Here, the element 0 is the minimum element in the array.

// Example 2:
// Input : nums = [3, 4, 5, 1, 2]

// Output: 1


// *** optimal Approach ***
// Appraoch: 1. By examing some examples we get to know that min may or may not be present in the soretd part
//           2. So first we take advantage of sorted part, we know that min in sorted part in first element of that part
//           3. first we initialize ans = INT_MAX, then to minimum in sorted part i.e ans = min(ans, first element of sorted part)
//           4. Now we can element the part sorted part because we already found least element in it
//           5. i.e low = middle +1 if sorted part is left or high = middle -1 if sorted part is right

class Solution {
public:
    int findMin(vector<int> &nums)  {
        int ans = INT_MAX;
        int low = 0;
        int high = (int)nums.size()-1;
        while(low <= high) {
            int middle = low + (high - low)/2;
            if(nums[low] <= nums[middle]) {
                ans = min(ans, nums[low]);
                low = middle +1;
            }else {
                ans = min(ans, nums[middle]);
                high = middle-1;
            }
        }
        return ans;
    }
};

//Time complexity: O(logN)
//Space complexity: O(1)
