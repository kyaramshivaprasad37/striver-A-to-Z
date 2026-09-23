#include <iostream>
using namespace std;
class Solution {
  public:
    int num(int x) {
        int digits = 0;
        while (x != 0) {
            x = x / 10;
            digits++;
        }
        return digits;
    }
};

int main() {
    int n;
    cin >> n;
    Solution s{};
    cout << s.num(n);
    return 0;
}
