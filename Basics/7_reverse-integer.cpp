

// code_start

class Solution {
  public:
    long rev = 0;
    int reverse(int x) {
        while (x != 0) {
            rev = rev * 10 + x % 10;
            x = x / 10;
            if (rev > INT_MAX || rev < INT_MIN) {
                return 0;
            }
        }
        return rev;
    }
};

// code_end
