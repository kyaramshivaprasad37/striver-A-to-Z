// 1781. Sum of Beauty of All Substrings

// Medium    likes: 1702    dislikes: 230    Solve it    Link    Solution

// The beauty of a string is the difference in frequencies between the most
// frequent and least frequent characters.

// * For example, the beauty of "abaacc" is 3 - 1 = 2.

// Given a string s, return the sum of beauty of all of its substrings.

// Example 1:

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are
// ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

// Example 2:

// Input: s = "aabcbaa"
// Output: 17

// code_start

class Solution {
  public:
    int beautySum(string s) {
        int len = s.size();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            map<char, int> mpp;

            for (int j = i; j < len; j++) {
                int high = INT_MIN;
                int low = INT_MAX;
                mpp[s[j]]++;
                for (auto [key, value] : mpp) {
                    if (value < low) {
                        low = value;
                    }
                    if (value > high) {
                        high = value;
                    }
                }
                sum += (high - low);
            }
        }
        return sum;
    }
};

// code_end

// Time Complexity : O(n^2)
// Space Complexity : O(1)
