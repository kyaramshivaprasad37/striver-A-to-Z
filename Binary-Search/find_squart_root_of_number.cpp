// 786. Find square root of a number
// Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).

// Example 1:
// Input: n = 36

// Output: 6

// Explanation: 6 is the square root of 36.

// Example 2:
// Input: n = 28

// Output: 5

// Explanation: The square root of 28 is approximately 5.292. So, the floor value will be 5.

// *** optimal Approach ***
// Approach: we are finding the lower bound
//          if its equal to n we return low else we return low - 1


class Solution {
public:
    int floorSqrt(int n)  {
        int low = 1;
        int high = n;
        while(low <= high) {
            int middle = low + (high - low)/2;
            if(middle * middle >= n) {
                high = middle -1;
            }else {
                low = middle + 1;
            }
        }
        if(low*low == n) {
            return low;
        }else {
            return low- 1;
        }
    }
};

// Time complexity: O(log(n))
// space complexity: O(1)
