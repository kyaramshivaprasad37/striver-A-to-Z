// Given a sorted array of nums consisting of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// Example 1:
// Input: nums = [1, 3, 5, 6], target = 5

// Output: 2

// Explanation: The target value 5 is found at index 2 in the sorted array. Hence, the function returns 2.

// Example 2:
// Input: nums = [1, 3, 5, 6], target = 2

// Output: 1

// Explanation: The target value 2 is not found in the array. However, it should be inserted at index 1 to maintain the sorted order of the array.


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return 1;
        }else if(nums[nums.size()-1] < target) {
            return nums.size();
        }
        int low = 0;
        int high = (int)nums.size()-1;
        int middle;
        int ans;
        while(low<=high) {
            middle = low+(high-low)/2;
            if(nums[middle] == target) {
                return middle;
            }

            if(nums[middle] > target) {
                ans = middle;
                high= middle-1;
            }else {
                low = middle +1;
            }
        }
        return ans;
    }
}

//Time Complexity: O(logn)
//Space Complexity: O(1)
