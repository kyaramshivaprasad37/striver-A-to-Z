// 5. Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"

// *** Brute Force ***

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int len = s.size();
//         int i = 0;
//         int j = len - 1;
//         while(i < j) {
//             if(s[i] != s[j]) {
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         int len = s.size();
//         string maxstring = "";
//         for(int i = 0; i < len; i++) {
//             string temp = "";
//             for(int j = i;j < len;j++) {
//                 temp += s[j];
//                 if(isPalindrome(temp)){
//                     if(maxstring.size() <= temp.size()) {
//                         maxstring = temp;
//                     }
//                 };
//             }
//         }
//         return maxstring;
//     }
// }

//Time Complexity: O(n x n x n)
//Space Complexity : O(n)

//*** Optimal Solution ***

// code_start

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1) {
            return s;
        }
        string lps = "";
        for(int i = 0; i < len;i++) {
            int low = i;
            int high = i;
            while(low >= 0 && high < len && s[low] == s[high]){
                low--;
                high++;
            }

            string palindrome = s.substr(low+1, high-low-1);
            if(palindrome.size() > lps.size()) {
                lps = palindrome;
            }

            low = i-1;
            high = i;
            while(low >= 0 && high < len && s[low] == s[high]) {
                low--;
                high++;
            }

            palindrome = s.substr(low + 1, high-low-1);
            if(palindrome.size() > lps.size()) {
                lps = palindrome;
            }
         }
        return lps;
    }
};

// code_end

//Time Complexity: O(n x n)
//Space Complexity: O(1)
