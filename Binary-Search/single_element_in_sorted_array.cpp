// 224. Single element in sorted array
// Given an array nums sorted in non-decreasing order. Every number in the array except one appears twice. Find the single number in the array.

// Example 1:
// Input :nums = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]

// Output:4

// Explanation: Only the number 4 appears once in the array.

// Example 2:
// Input : nums = [1, 1, 3, 5, 5]

// Output:3

// *** optimal Approach ***
// Approach : 1. By examing some examples we will have
//            2. [1,1,3,5,5]  that on left part for even index (i), i+1 should be same and for odd part, i-1 should be same
//            3. that means we are on the left part so low = middle+1
//            4. else high = middle -1
//            5. returning codition is checking left and right if both are not same
//            6. since we are checking left and right we have problem at first and last element
//            7. so check them first and start binary search from 1 -- n-2;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        if(nums[0] != nums[1]) {
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]) {
            return nums[n-1];
        }
        int low = 0;
        int high = n-2;
        while(low <= high) {
            int middle = low + (high - low)/2;
            if(nums[middle] != nums[middle-1] && nums[middle] != nums[middle+1]){
                return nums[middle];
            }

            if((middle % 2 == 0 && nums[middle] == nums[middle+1]) || middle % 2 == 1 && nums[middle] == nums[middle-1]) {
                low = middle +1;
            }else {
                high = middle -1;
            }
        }
        return -1;
    }
};

//Time Complexity: O(Log(n))
//Space complexity: O(1)
