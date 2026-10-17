// 46. Search in rotated sorted array-I
// Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.

// Example 1:
// Input : nums = [4, 5, 6, 7, 0, 1, 2], k = 0

// Output: 4

// Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

// Example 2:
// Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3

// Output: -1

// Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.

// *** Optimal Approach ***
// Approach : 1. since array is rotated either right or left part will be sorted
//            2. first if check for sorted one i.e by checking low and middle
//               i. then we check if target is in between low -- middle or middle -- high and then move the pointers according to it
//            3. else
//               i. then we check if target is in between low -- middle or middle -- high and then move the pointers according to it

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size()-1;
        while(low <= high) {
            int middle = low+(high-low)/2;
            if(nums[middle] == target) {
                return middle;
            }

            if(nums[low] <= nums[middle]) {
                if(nums[low] <= target && target <= nums[middle]) {
                    high = middle-1;
                }else {
                    low = middle+1;
                }
            }else {
                if(nums[middle] <= target && target <= nums[high]) {
                    low = middle +1;
                }else {
                    high = middle -1;
                }
            }
        }
        return -1;
    }
};

// Time complexity : O(log(n))
// Space complexity: O(1)
