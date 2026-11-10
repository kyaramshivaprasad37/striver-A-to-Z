// 65. Minimize Max Distance to Gas Station
// Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis.
//
// The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.
//
// Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.
//
// Find the minimum value of dist.
//
// Your answer will be accepted if it is within 1e-6 of the true value.
//
// Example 1:
// Input: n = 10, arr = [1, 2, 3, 4, 5, 6 ,7, 8, 9, 10], k = 10
//
// Output: 0.50000
//
// Explanation:
//
// There are initially 10 gas stations from 1 to 10. We need to add 10 new gas stations.
// Place the new stations at: [1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5]
// The resulting positions are: [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 10.5]
// The maximum distance between adjacent gas stations is 0.5.
// Hence, the minimum possible value of dist is 0.5.
// Example 2:
// Input : n = 10, arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 1
//
// Output: 1.00000
//
// Explanation:
//
// One of the possible ways to place 1 gas station is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
// New Gas Station is at 11.
// Thus the maximum difference between adjacent gas stations is still 1.
// Hence, the value of dist is 1.
// It can be shown that there is no possible way to add 1 gas station in such a way that the value of dist is lower than this. 

// *** Brute Force *** 

class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howmany(n-1, 0);
        for(int g = 1; g <= k; g++) {
            long double maxval = -1; int maxindex = -1;
            for(int i = 0; i < n-1; i++) {
                 long double diff = stations[i+1] - stations[i];
                 long double sectionLength = diff / (long double)(howmany[i] + 1);
                 if(maxval < sectionLength) {
                     maxval = sectionLength;
                     maxindex = i;
                 }
            }
            howmany[maxindex]++;
        }
        
        long double maxans = -1;
        for(int i = 0; i < n-1;i++) {
            long double sectionLen = (stations[i+1] - stations[i])/(long double)(howmany[i] + 1);
            maxans = max(sectionLen, maxans);
        }
        return maxans;
    }
};

//Time Complexity: O(k x n) + O(n)
//Space Complexity: O(1)

// *** Better Solution *** 

class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howMany(n-1, 0);
        priority_queue<pair<long double, int>> pq;
        for(int i = 0; i < n-1; i++) {
            pq.push({stations[i+1] - stations[i], i});
        }
        
        for(int gasStations = 1; gasStations <= k;gasStations++) {
            auto tp = pq.top(); pq.pop();
            int secInd = tp.second;
            howMany[secInd]++;
            long double iniDiff = stations[secInd + 1] - stations[secInd];
            long double newSecLen = iniDiff / (long double) (howMany[secInd] + 1);
            pq.push({newSecLen, secInd});
        }
        return pq.top().first;
    }
};

//Time Complexity: O(nlogn + klogn)
//Space Complexity: O(n-1)


// *** Optimal Solution ***

class Solution {
  public:
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int cnt = 0;
        for(int i = 1; i < arr.size(); i++) {
            int numberInBetween = ((arr[i] - arr[i-1]) / dist);
            if((arr[i] - arr[i-1])/dist == numberInBetweem * dist) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    double minMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0;
        long double high = 0;
        for(int i = 0; i < n-1;i++) {
            high = max(high, (long double)(arr[i+1] - arr[i]));
        }

        long double diff = 1e-6;
        while(high - low > diff){
            long double mid = (low + high)/(2.0);
            int cnt = numberOfGasStationsRequired(mid, arr);
            if(cnt > k){
                low = mid;
            }else {
                high - mid;
            }
        }
        return high;
    }
}

//Time Complexity: O(nlogn + n) 
//Space Complexity: O(1)
