// 185. Find Nth root of a number
// Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.

// Example 1:
// Input: N = 3, M = 27

// Output: 3

// Explanation: The cube root of 27 is equal to 3.

// Example 2:
// Input: N = 4, M = 69

// Output:-1

// Explanation: The 4th root of 69 does not exist. So, the answer is -1.


// *** optimal Approach ***
// Approach: 1.first we take low = 1 and high = M
//           2. then like binary search we check if middle ^ n condition
//           3. we check power value using a helper function
//           4. in which it loops from 1 --> N and
//           5. if ans == M if return 0
//           6. if ans > M return 1
//           7. else -1 by this we adjust low and high

class Solution {
public:
    int fun(int middle, int N, int M) {
        long long ans = 1;
        for(int i = 0; i < N; i++) {
            ans *= middle;
            if(ans > M) {
                return 1;
            }
        }
        if(ans == M) {
            return 0;
        }
        return -1;
    }

  int NthRoot(int N, int M) {
        int low = 1;
        int high = M;
        while(low <= high) {
            int middle = low + (high - low)/2;
            int ans = fun(middle, N, M);
            if(ans == 0) {
                return middle;
            }else if(ans == 1) {
                high = middle -1;
            }else {
                low = middle + 1;
            }
        }
        return -1;
    }
};

// Time complexity: O(N LogM)
// Space complexity: O(1)
