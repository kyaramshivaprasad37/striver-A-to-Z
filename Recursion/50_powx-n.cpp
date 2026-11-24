// 50. Pow(x, n)

// Medium    likes: 12083    dislikes: 10701    Solve it    Link    Solution

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100

// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

// Optimal Appraach :
// Approach : lets take 2^10 as example
//            1. 2^10 = (2*2)^5
//            2, 4^5 = 4 * (4^4)
//            3. 4^4 = (4*4)^2
//            4. 16^2 = (16 * 16)^1
//            so if n is even we do x = x*x and n = n/2
//            and if odd we do ans = ans * x and n = n-1;

// code_start

class Solution {
  public:
    double myPow(double x, int n) {
        double ans = 1;
        long nn = n;
        if (nn < 0) {
            nn = nn * -1;
        }
        while (nn > 0) {
            if (nn % 2 == 1) {
                ans = ans * x;
                nn = nn - 1;
            } else {
                nn = nn / 2;
                x = x * x;
            }
        }
        if (n < 0) {
            ans = double(1.0) / double(ans);
        }
        return ans;
    }
};

// code_end

// Time Complexity : O(log(n))
// Space Complexity: (1)
