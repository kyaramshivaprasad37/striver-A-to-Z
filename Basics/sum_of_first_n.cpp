#include <iostream>
using namespace std;

int fun(int n, int i) {
    cout << i << ' ';
    if (n == i) {
        return 0;
    }
    i++;
    return fun(n, i);
}

int main() {
    int n;
    cin >> n;
    fun(n, 0);
    return 0;
}
