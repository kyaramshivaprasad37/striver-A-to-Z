// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.



// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

// *** Optimal Approach ***
// Approach : 1. define an unordered map
//            2. define mpp[0] = 1 for arrays containing one elements with k value
//            3. initailize sum and increment with every iteration sum += a[i]
//            4. now rem = sum - k
//            5. if rem is found in mpp increase to to that rem data value rem (20 , 1)
//            6. at last add sum t map and increase it value

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long, long> mpp;
        mpp[0] = 1;
        int count = 0;
        long sum;
        for(int i = 0; i < nums.size();i++) {
            sum += nums[i];
            long rem = sum-k;
            if(mpp.find(rem) != mpp.end()) {
                count += mpp[rem];
            }
            mpp[sum]++;
        }
        return count;
    }
};

//Time complexity: (N)
//Space complexityL O(N)
