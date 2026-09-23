// #include <iostream>
// #include <vector>
// using namespace std;
//
// class Solution {
//   public:
//     int fun(vector<int> a, int k) {
//         int n = a.size();
//         int s, e;
//         bool is = false;
//         int maxlen{};
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += a[j];
//                 if (sum == k) {
//                     s = i;
//                     e = j;
//                     is = true;
//                     int len = e - s;
//                     if (maxlen < len) {
//                         maxlen = len;
//                     }
//                 }
//             }
//         }
//         if (is) {
//             return maxlen + 1;
//         } else {
//             return 0;
//         }
//     }
// };
//
// int main() {
//     Solution s;
//     int k;
//     cin >> k;
//     vector<int> a{-1, 1, 1};
//     cout << s.fun(a, k);
// }

// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
// 		int a[10] = {1,2,3,1,1,1,1,4,2,3};
// 		int n = sizeof(a)/sizeof(a[0]);
// 		int k = 3;
// 		int sum=0;
// 		int maxLen = 0;
// 		map<int, int> preSum;
//
// 		for(int i =0;i<n;i++){
// 				sum+=a[i];
// 				if(sum == k){
// 						maxLen = max(maxLen, i+1);
// 				}
// 				int rem = sum - k;
// 				if(preSum.find(rem) != preSum.end()) {
// 						int len = i - preSum[rem];
// 						maxLen = max(maxLen,len);
// 				}
// 				if(preSum.find(sum) == preSum.end()){
// 						preSum[sum] = i;
// 				}
// 		}
// 		cout << maxLen << '\n';
// 		return 0;
// }

#include <iostream>
using namespace std;

int main() {
		int a[10] = {1,2,3,1,1,1,1,4,2,3};
		int n = sizeof(a)/sizeof(a[0]);
		int k = 6;
		int sum=a[0];
		int maxLen = 0;
		int i = 0;
		int j= 0;
		while(i < n){
				while(j <= i && sum > k) {
						sum -= a[j];
						j++;
				}
				if(sum == k) {
						maxLen = max(maxLen, i-j+1);
				}
				i++;
				if(i < n) sum += a[i];
		}
		cout << maxLen << '\n';
}























