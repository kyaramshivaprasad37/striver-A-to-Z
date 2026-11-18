// 1614. Maximum Nesting Depth of the Parentheses

// Given a valid parentheses string s, return the nesting depth of s. The
// nesting depth is the maximum number of nested parentheses.

// Example 1:

// Input: s = "(1+(2*3)+((8)/4))+1"

// Output: 3

// Explanation:

// Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:

// Input: s = "(1)+((2))+(((3)))"

// Output: 3

// Explanation:

// Digit 3 is inside of 3 nested parentheses in the string.

// Example 3:

// Input: s = "()(())((()()))"

// Output: 3

// code_start

class Solution {
  public:
    int maxDepth(string s) {
        int count = 0;
        int mx = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') {
                count++;
                mx = max(count, mx);
            } else if (ch == ')') {
                count--;
            }
        }
        return mx;
    }
};

// code_end

// Time Complexity : O(n)
// Space complexity : O(1)
