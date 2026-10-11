// 163. Count subarrays with given xor K
// Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

// Example 1:
// Input : nums = [4, 2, 2, 6, 4], k = 6

// Output : 4

// Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]

// Example 2:
// Input :nums = [5, 6, 7, 8, 9], k = 5

// Output : 2

// Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]


// *** Brute Force ***
// Approach: 1. loop through every subarray using two for loops i = 0 --> n-1 and j = i ---> n-1
//           2. use the third for loop to calculate xor of each element from the subarray
//           3. if that xor is equal to k --> count++

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n;i++) {
            for(int j = i; j < n;j++) {
                int xorr = 0;
                for(int k = i;k <= j;k++) {
                    xorr = xorr ^ nums[k];
                }
                if(xorr == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

//Time Complexity: O(n x n x n)
//Space Complexity: O(1)


// *** Better Solution ***
// Approach: By eliminating the need for third loop

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n;i++) {
            int xorr = 0;
            for(int j = i; j < n;j++) {
                xorr = xorr ^ nums[j];
                if(xorr == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

//Time Complexity: O(n x n)
//Space Complexity: O(1)


// *** Optimal ***
// Approach: 1. let xR be the XOR of elements of each iteration 0->n-1  XR = xR ^ nums[i]
//           2. wkt x = xR ^ k
//           3. we take a hashmap and insert xR and its count(how many times it appeared) into it
//           4. then we increment count by x's value in hashmap

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        int count = 0;
        int xR = 0;
        mpp[0] = 1;
        for(int i = 0; i < n;i++) {
            xR = xR ^ nums[i];
            int x = xR ^ k;
            count += mpp[x];
            mpp[xR]++;
        }
        return count;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)
