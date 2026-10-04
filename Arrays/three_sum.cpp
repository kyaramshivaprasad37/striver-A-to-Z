// Given an integer array nums. Return all triplets such that:

// i != j, i != k, and j != k
// nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets. One element
// can be a part of multiple triplets. The output and the triplets can be
// returned in any order.

// Example 1:
// Input: nums = [2, -2, 0, 3, -3, 5]

// Output: [[-2, 0, 2], [-3, -2, 5], [-3, 0, 3]]

// Explanation:

// nums[1] + nums[2] + nums[0] = 0

// nums[4] + nums[1] + nums[5] = 0

// nums[4] + nums[2] + nums[3] = 0

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &a) {
        int n = a.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (a[i] + a[j] + a[k] == 0) {
                        vector<int> temp = {a[i], a[j], a[j]};
                        sort(temp.beg(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    };

    // Approach: by taking two loops and taking third element as -(a[i] + a[j])
    // and inserting the a[j] element into hashmap before moving to next elemrnt
    // of ith loop if third element is found in hashmap then insert those three
    // elements into an temp array then sort the array for removing duplicating
    // while inserting in set then at the last insert those set elements into 2d
    // array and return the that array

    class Solution {
      public:
        vector<vector<int>> threeSum(vector<int> &nums) {
            int n = nums.size();
            set<vector<int>> st;
            for (int i = 0; i < n; i++) {
                set<int> hashset;
                for (int j = i + 1; j < n; j++) {
                    int third = -(nums[i] + nums[j]);
                    if (hashset.find(third) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], third};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[j]);
                }
            }
            vector<vector<int>> ans(st.begin(), st.end());
            return ans;
        }
    };

    // Time Complexity: O(n x n x log(M))  M - variable
    //  Space complexity: O(n) + O(M x 2)

    // **** Optimal Approach ****
    // first sort the given array
    // then take three pointer i-fixed, j = i+1, k = n-1
    // if(sum < 0) move j ---> j++
    // if(sum > 0) move k ---> k--
    // if(sum == 0) insert those three elements into the set then move j and k
    // both util the element is not eqaul to previous move j and k until j < k
    // them move i

    class Solution {
      public:
        vector<vector<int>> threeSum(vector<int> &nums) {
            int n = nums.size();
            set<vector<int>> st;
            for (int i = 0; i < n; i++) {
                set<int> hashset;
                for (int j = i + 1; j < n; j++) {
                    int third = -(nums[i] + nums[j]);
                    if (hashset.find(third) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], third};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[j]);
                }
            }
            vector<vector<int>> ans(st.begin(), st.end());
            return ans;
        }
    };

    // Time Complexity: O(nlog(n)) + O(nxn)
    // Space Complexity: O(no of unique ele)
