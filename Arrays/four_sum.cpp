// Given an array nums of n integers, return an array of all the unique
// quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

//   *** Better Approach ***
// Approach: using hashmap

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &a, int target) {
        int n = a.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<int> hashset;
                for (int k = j + 1; k < n; k++) {
                    int fourth = target - (a[i] + a[j] + a[k]);
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {a[i], a[j], a[k], fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(a[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// Time Complexity: O(nxnxn)
// Space Complexitu: 0(no of triplets)

// *** Optimal Approach ***
// Approach: 1. sort the array
//          2. use i and j as two loop for as fixed pointers
//          3. use another two pointers ptr1 = j+1 and ptr2 = n-1
//          4. Now check of sum == taget
//          5. if yes move ptr1 and ptr2 to new element
//          6. if sum < target move ptr1
//          7. if sum > target move ptr2
//          8. make sure after the loop i and j comleted one loop move them to
//          new element

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &a, int target) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && a[j] == a[j - 1])
                    continue;
                int ptr1 = j + 1;
                int ptr2 = n - 1;
                while (ptr1 < ptr2) {
                    long long sum = a[i];
                    sum += a[j];
                    sum += a[ptr1];
                    sum += a[ptr2];
                    if (sum == target) {
                        vector<int> temp = {a[i], a[j], a[ptr1], a[ptr2]};
                        ans.push_back(temp);
                        ptr1++;
                        ptr2--;
                        while (ptr1 < ptr2 && a[ptr1] == a[ptr1 - 1]) {
                            ptr1++;
                        }
                        while (ptr1 < ptr2 && a[ptr2] == a[ptr2 + 1]) {
                            ptr2--;
                        }
                    } else if (sum < target) {
                        ptr1++;
                    } else {
                        ptr2--;
                    }
                }
            }
        }
        return ans;
    }
};

// Time Complexity: O(n x n x n)
// Space Complexity: O(1)
