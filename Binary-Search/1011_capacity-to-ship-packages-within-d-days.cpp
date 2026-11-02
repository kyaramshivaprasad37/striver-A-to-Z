// A conveyor belt has packages that must be shipped from one port to another within days
// days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship
// with packages on the conveyor belt (in the order given by weights). We may not load more
// weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor
// belt being shipped within days days.



// Example 1:


// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

// Example 2:


// Input: weights = [3,2,2,4,1,4], days = 3
// Output: 6
// Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
// 1st day: 3, 2
// 2nd day: 2, 4
// 3rd day: 1, 4

// Example 3:


// Input: weights = [1,2,3,1,1], days = 4
// Output: 3
// Explanation:
// 1st day: 1
// 2nd day: 2
// 3rd day: 3
// 4th day: 1, 1


//  *** optimal appraoch ***
// Approach: 1.to find least capacity first we have to set a boundary
//           2.i.e the capacity cannot be less than the large element in package if so it cant fit in ship
//           3. and max capacity can be sum of elements in array(sum of weights)
//           4. so now we have boundary i.e from max_element to sum of elements
//           5. now we can select from capacity and check is with this capacity the days required or not using fun
//           6. we can adapt this for binary search using low = max_element and high = sum_of_elements
//           7. and if days req is less than given ---> high = mid -1
//           8. else low = mid + 1
//           9. return low

}

// code_start

class Solution {
public:
    int daysReq(vector<int> weights, int capacity) {
        int count = 0;
        long long sum = 0;
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if(sum > capacity) {
                sum = weights[i];
                count++;
            }
        }
        return count + 1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += weights[i];
        }
        long long high = sum;
        while(low <= high) {
            int capacity = low + (high - low)/2;
            int ans = daysReq(weights, capacity);
                if(ans <= days) {
                    high = capacity - 1;
                }else {
                    low = capacity + 1;
                }
        }
        return low;
    }
};

// code_end

// Time Complexity: O(log(sum - max + 1) *n)
// Space complexity: O(1)
