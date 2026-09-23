#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int fun(vector<int> &a, int low, int high) {
        int pivot = a[low];
        int i = low;
        int j = high;
        while (i < j) {
            while (a[i] <= pivot && i <= high) {
                i++;
            }
            while (a[j] > pivot && j >= low) {
                j--;
            }
            if (i < j) {
                swap(a[i], a[j]);
            }
        }
        swap(a[low], a[j]);
        return j;
    }
    void sort(vector<int> &a, int low, int high) {
        if (low < high) {
            int pivotindex = fun(a, low, high);
            sort(a, low, pivotindex - 1);
            sort(a, pivotindex + 1, high);
        }
    }
};

int main() {
    vector a{4, 6, 2, 5, 7, 9, 1, 3};
    Solution s;
    s.sort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
