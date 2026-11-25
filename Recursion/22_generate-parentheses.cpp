

// code_start

class Solution {
  public:
    void helper(vector<string> &res, int n, int openN, int closeN,
                string temp) {
        if (openN == n && closeN == n) {
            res.push_back(temp);
            return;
        }

        if (openN < n) {
            helper(res, n, openN + 1, closeN, temp + "(");
        }
        if (closeN < openN) {
            helper(res, n, openN, closeN + 1, temp + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, n, 0, 0, "");
        return res;
    }
};

// code_end
