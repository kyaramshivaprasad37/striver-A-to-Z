// Given an array nums of n integers.

// Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

// Example 1:
// Input: nums = [100, 4, 200, 1, 3, 2]

// Output: 4

// Explanation:

// The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

// Example 2:
// Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

// Output: 9

// Explanation:

// The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.


// *** Brute Force ***
class Solution {
public:
    bool Linear(vector<int> nums, int tar) {
        for(int i = 0; i < nums.size();i++) {
            if(nums[i] == tar) {
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
       int n = nums.size();
       int lc = 0;
       for(int i =0;i < n;i++) {
        int m = nums[i];
        int cnt = 1;
        while(Linear(nums, m+1)) {
            m = m+1;
            cnt += 1;
        }
        if(cnt >= lc) {
            lc = cnt;
        }
       }
       return lc;
    }
};

//Time Complexity: O(n x n)
//Space complexity: O(1)


// *** Better Approach ***
// Approach: 1. sort the array
//           2. using for loop check  if prev element is == curr
//           3. if yes increase count
//           4. if not equal reset count

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int longest = 0;
        int cnt = 0;
        int prev = INT_MIN;
        for(int i = 0;i < n;i++) {
            int curr = nums[i];
            if(curr-1 == prev) {
                cnt++;
                prev = curr;
            }else if(prev != curr){
                cnt = 0;
                prev = curr;
            }
            if(cnt > longest) {
                longest = cnt;
            }
        }
        return longest+1;
    }
};

//Time Complexity: O(nlogn + n)
//Space complexity: O(1)

// *** Optimal Approach ***
// Approach: 1.insert every element in an unordered set
//           2.iterate in set and check if there isnt any element 1 less than curr
//           3.that means probably it may be first element in the sequeuce
//           4.then using while loop check if there is an element = curr +1
//           5. if yes increase the count and curr = curr +1


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n = nums.size();
       int longest = 0;
       unordered_set<int> st;
       for(int i = 0; i < n;i++) {
        st.insert(nums[i]);
       }
       for(auto it:st) {
        if(st.find(it-1) == st.end()) {
            int cnt = 1;
            int x = it;
            while(st.find(it+1) != st.end()) {
                it = it+1;
                cnt = cnt +1;
            }
            longest = max(longest, cnt);
        }
       }
        return longest;
    }
};
