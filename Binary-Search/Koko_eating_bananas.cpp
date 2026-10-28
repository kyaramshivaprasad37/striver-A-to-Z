// 91. Koko eating bananas
// A monkey is given n piles of bananas, where the 'ith' pile has nums[i] bananas. An integer h represents the total time in hours to eat all the bananas.

// Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas. If the pile contains fewer than k bananas, the monkey eats all the bananas in that pile and does not consume any more bananas in that hour.

// Determine the minimum number of bananas the monkey must eat per hour to finish all the bananas within h hours.

// Example 1:
// Input: n = 4, nums = [7, 15, 6, 3], h = 8

// Output: 5

// Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.

// Example 2:
// Input: n = 5, nums = [25, 12, 8, 14, 19], h = 5

// Output: 25

// Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. So, he will take 5 hours to complete all the piles


// *** optimal Approach ***
// Approach: 1. we have to find min int K such that koko can all bananas within h hours
//           2. k ---> no of bananas koko can eat per hours (bananas/hour)
//           3. if we take pile as [3 6 7 11] and h = 8 and k = 2 lets sat
//           4. then we get 3/2--> 1.5 but koko can not allowed to spend rest time on next one so 3/2 ends up 2, 6/2 = 3, 7/2 = 4, 11/4 = 5
//           5. 2 + 3 + 4 + 6 = 15 > h so we have to find lowest than h
//           6. we can use binary search with boundary 1 to max_element in pile, because taking k greater than max element will ans as size of pile
//           7. we use helper fun to cal sum with using ceil and if sum > h ---> low = middle + 1 else high = middle -1
//           8. return low

class Solution {
public:
    int fun(vector<int> piles, int middle, int h) {
        long long sum = 0;
        for(int i = 0; i < piles.size(); i++) {
            sum += ceil((double)piles[i]/(double)middle);
            if(sum > h) {
                return 1;
            }
        }
        if(sum <= h) {
            return 0;
        }
        return -1;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high) {
            int middle = low + (high - low)/2;
            int ans = fun(piles, middle, h);
            if(ans == 1) {
                low = middle + 1;
            }else {
                high = middle - 1;
            }
        }
        return low;
    }
};

//Time complexity: O(Nlog(max_ele))
//Space complexity: O(1)
