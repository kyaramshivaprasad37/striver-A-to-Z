// 139. Aggressive Cows
// Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows,
// assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.

// Example 1:
// Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

// Output: 3

// Explanation:

// The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10].
// Here the distances between cows are 3, 4, and 3 respectively.

// In no manner can we increase the minimum distance beyond 3.

// Example 2:
// Input : n = 5, k = 2, nums = [4, 2, 1, 3, 6]

// Output: 5

// Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions [1, 6].


// *** Brute force ***
// Approach: 1. we have to find the max of min distances that cows can be assigned
//           2. first we sort the array because for checking min we just need to check the adjacent elements if the array is sorted
//           3. then we check from {0 to nums[n-1] - nums[0]}
//           4. we pass this value to function that checks is it possible to fit all cows with this value
//           5. FUN: it check nums[j] - nums[i] >= m(the value passed to fun) if true increase count and i = j and j++;
//           6. else j++;
//           7. at last after the loop check is count >= k(no.of cows) if yes ---> return true else false

class Solution {
public:
    bool fun(vector<int> nums, int k, int m) {
        int i = 0;
        int j = 1;
        int count = 1;
        while(j < nums.size()) {
            if(nums[j] - nums[i] >= m) {
                i = j;
                j++;
                count++;
            }else {
                j++;
            }
        }
        if(count >= k){
            return true;
        }else {
            return false;
        }
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        for(int i = 0; i <= high; i++) {
            bool possible = fun(nums, k, i);
            if(possible) {
                ans = max(ans , i);
            }else {
                return ans;
            }
        }
    }
};

//Time complexity(O(max-min) x n)
//space complexity:O(1)


// *** Optimal Soultion ***
// Approach : 1. instead of checking ans from 1 to max- min
//            2. we use binary search and check is possible low = mid +1 else high = mid -1
//            3. return high


class Solution {
public:
    bool fun(vector<int> nums, int k, int m) {
        int i = 0;
        int j = 1;
        int count = 1;
        while(j < nums.size()) {
            if(nums[j] - nums[i] >= m) {
                i = j;
                j++;
                count++;
            }else {
                j++;
            }
        }
        if(count >= k){
            return true;
        }else {
            return false;
        }
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int low = 1;
        int high = nums[n-1] - nums[0];
        while(low <= high) {
            int mid = low + (high - low)/2;
            bool possible = fun(nums, k, mid);
            if(possible) {
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return high;
    }
};

// Time complexity: log(n) + (log(max - min) x n)
// space complexity: (1)
