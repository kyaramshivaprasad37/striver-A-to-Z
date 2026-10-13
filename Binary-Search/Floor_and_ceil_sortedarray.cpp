// Given a sorted array nums and an integer x. Find the floor and ceil of x in nums.
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.

// Example 1:
// Input : nums =[3, 4, 4, 7, 8, 10], x= 5

// Output: 4 7

// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// Example 2:
// Input : nums =[3, 4, 4, 7, 8, 10], x= 8

// Output: 8 8

// Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int low = 0;
        int high = (int)nums.size()-1;
        int floor= -1;
        int ceil = -1;
        while(low <= high) {
            int middle = low+(high-low)/2;
            if(nums[middle] >= x) {
                ceil = nums[middle];
                high = middle -1;
            }else{
                low = middle+1;
            }
        }

        int low1 = 0;
        int high1 = (int)nums.size()-1;
        while(low1 <= high1) {
            int middle = low1+(high1-low1)/2;
            if(nums[middle] <= x) {
                floor = nums[middle];
                low1 = middle+1;
            }else{
                high1 = middle-1;
            }
        }

        return {floor,ceil};
    }
};

//Time Complexity: O(logn)
//Space complexity: O(1)
