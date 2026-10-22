// 839. Count Occurrences in a Sorted Array
// You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.

// Return the count of occurrences of target in the array.

// Example 1:
// Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1

// Output: 3

// Explanation: The number 1 appears 3 times in the array.

// Example 2:
// Input: arr = [5, 5, 5, 5, 5, 5], target = 5

// Output: 6

// Explanation: All elements in the array are 5, so the target appears 6 times.

// *** optimal Approach ***
// Approach: finding lower and upper bound and return upper - lower
//           if lower == -1 or arr[low] != target return 0

class Solution {
public:

    int lowerBound(vector<int>& arr,int target) {
        int low = 0;
        int high = (int)arr.size()-1;
        int ans = -1;
        while(low <= high) {
            int middle = low + (high - low)/2;
            if(arr[middle] >= target) {
                ans = middle;
                high = middle - 1;
            }else {
                low = middle + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& arr, int target) {
        int low = 0;
        int high = (int)arr.size()-1;
        int ans = arr.size();
        while(low <= high) {
            int middle = low + (high - low)/2;
            if(arr[middle] > target) {
                ans = middle;
                high = middle - 1;
            }else {
                low = middle + 1;
            }
        }
        return ans;
    }

    int countOccurrences(vector<int>& arr, int target) {
        int first = lowerBound(arr, target);
        if(first == -1 && arr[first] != target) {
            return 0;
        }
        int last = upperBound(arr, target);
        return last - first;
    }
};

//Time Complexity: 2 log(n)
//Space complexity: O(1)
