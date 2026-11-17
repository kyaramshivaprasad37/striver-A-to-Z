// 1021. Remove Outermost Parentheses

// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where
// A and B are valid parentheses strings, and + represents string concatenation.

// * For example, "", "()", "(())()", and "(()(()))" are all valid parentheses
// strings.

// A valid parentheses string s is primitive if it is nonempty, and there does
// not exist a way to split it into s = A + B, with A and B nonempty valid
// parentheses strings.

// Given a valid parentheses string s, consider its primitive decomposition: s =
// P1 + P2 + ...
// + Pk, where Pi are primitive valid parentheses strings.

// Return s after removing the outermost parentheses of every primitive string
// in the primitive decomposition of s.

// Example 1:

// Input: s = "(()())(())"
// Output: "()()()"
// Explanation:
// The input string is "(()())(())", with primitive decomposition "(()())" +
// "(())". After removing outer parentheses of each part, this is "()()" + "()"
// = "()()()".

// Example 2:

// Input: s = "(()())(())(()(()))"
// Output: "()()()()(())"
// Explanation:
// The input string is "(()())(())(()(()))", with primitive decomposition
// "(()())" + "(())" + "(()(()))". After removing outer parentheses of each
// part, this is "()()" + "()" + "()(())" = "()()()()(())".

// Example 3:

// Input: s = "()()"
// Output: ""
// Explanation:
// The input string is "()()", with primitive decomposition "()" + "()".
// After removing outer parentheses of each part, this is "" + "" = "".

// Approach : using stack to push "(" and then if we encounter ")" we pop and if
// stack is empty i.e after every
//           valid parentesis we move that string to temp vector
//           at last we remove first and last elements from strings

class Solution {
  public:
    string removeOuterParentheses(string s) {
        vector<string> valid;
        stack<char> st;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                temp += s[i];
            } else {
                st.pop();
                temp += s[i];
            }

            if (st.empty()) {
                valid.push_back(temp);
                temp = "";
            }
        }
        string ans = "";
        for (int i = 0; i < valid.size(); i++) {
            string ch = valid[i];
            for (int j = 1; j < ch.size() - 1; j++) {
                ans += ch[j];
            }
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach : here instead of using stack to store and pop we are using a depth
//            if we encounter first opening if increase depth but not push to
//            ans but for second opening i.e depth > 0 we push that chat to ans
//            also for closing

class Solution {
  public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') {
                if (depth > 0) {
                    ans += ch;
                }
                depth++;
            } else {
                depth--;
                if (depth > 0) {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
