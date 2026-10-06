#include <iostream>
#include <vector>
using namespace std;

void permutations(vector<int> &original, vector<int> &ds,
                  vector<vector<int>> &ans, int freq[]) {
    if (ds.size() == original.size()) {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < original.size(); i++) {
        if (!freq[i]) {
            ds.push_back(original[i]);
            freq[i] = 1;
            permutations(original, ds, ans, freq);

            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main() {
    vector<int> original{1, 2, 3};
    vector<int> ds;
    vector<vector<int>> ans;
    int freq[original.size()] = {0};
    permutations(original, ds, ans, freq);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

// Time complexity: O(n x n!)
// Space complexity: O(n)
