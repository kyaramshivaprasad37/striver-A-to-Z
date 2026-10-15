// 279. First and last occurrence
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If the target is not found in the array, return [-1, -1].

// Example 1:
// Input: nums = [5, 7, 7, 8, 8, 10], target = 8

// Output: [3, 4]

// Explanation:The target is 8, and it appears in the array at indices 3 and 4, so the output is [3,4]

// Example 2:
// Input: nums = [5, 7, 7, 8, 8, 10], target = 6

// Output: [-1, -1]

// Expalantion: The target is 6, which is not present in the array. Therefore, the output is [-1, -1].


// *** Brute force ***
// Approach: using for loop check for first occurence if found insert as first = i (if first == -1) else last - i;

class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target) {

        int first = -1;
        int last = -1;

        for(int i = 0; i < nums.size();i++){
            if(nums[i]==target) {
                if(first == -1) {
                    first = i;
                }else {
                    last = i;
                }
            }
        }
        if(first != -1 && last == -1) {
            last = first;
        }
        return {first, last};
    }
};

//Time complexity: O(N)
//Space complexity: O(1)


//*** Optimal ***
//Appraoch: Using binary search with lower bound and upper bound

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.size() <= 0) {
            return {-1,-1};
        }

        int low = 0;
        int high = (int)nums.size()-1;
        int ans = nums.size();
        while(low <= high) {
            int middle = low+(high-low)/2;
            if(nums[middle] >= target) {
                ans = middle;
                high = middle-1;
            }else {
                low = middle+1;
            }
        }

        if(ans == nums.size() || nums[ans] != target) {
            return {-1,-1};
        }

        int last = nums.size();
        int low1 = 0;
        int high1 = (int)nums.size()-1;
        while(low1 <= high1) {
            int middle = low1+(high1-low1)/2;
            if(nums[middle] > target) {
                last = middle;
                high1 = middle-1;
            }else {
                low1 = middle +1;
            }
        }
        return {ans, last-1};
    }
};

//Time complexity: O(2 Log(n))
//Space complexity: O(1)
