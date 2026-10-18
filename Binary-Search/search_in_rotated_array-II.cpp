// 112. Search in rotated sorted array-II
// Given an integer array nums, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

// Example 1:
// Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3

// Output: True

// Explanation: The element 3 is present in the array. So, the answer is True.

// Example 2:
// Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10

// Output: False

// Explanation:The element 10 is not present in the array. So, the answer is False.


// *** optimal Approach ***
// Approach: same as I but with the edge case nums[low] == nums[mid] == num[high] -->> low++ and high--
//           by doing this we will eliminate the edge case

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size()-1;
        while(low <= high) {
            int middle = low + (high - low)/2;
            if(nums[middle] == target) {
                return true;
            }

            if(nums[low] == nums[middle] && nums[middle] == nums[high]) {
                low++;
                high--;
            }else if(nums[low] <= nums[middle]){
                if(nums[low] <= target && target <= nums[middle]) {
                    high = middle -1;
                }else {
                    low = middle+1;
                }
            }else {
                if(nums[middle] <= target && target <= nums[high]) {
                    low = middle +1;
                }else {
                    high = middle-1;
                }
            }
        }
        return false;
    }
};

//Time complexity: O(logn)
//Space complexity : O(1)
