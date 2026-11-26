#include <bits/stdc++.h>
using namespace std;

void palindrome(string s, int i, int n) {
    if (i == n / 2) {
        cout << "True" << '\n';
        return;
    }
    if (s[i] != s[n - i - 1]) {
        cout << "False" << '\n';
        return;
    }
    palindrome(s, i + 1, n);
}

int main() {
    string s = "MADAM";
    int n = s.size();
    palindrome(s, 0, n);
    return 0;
}
