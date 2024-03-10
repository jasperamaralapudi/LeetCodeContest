/*
You are given a 0-indexed array of integers nums of length n, and a positive odd integer k.

The strength of x subarrays is defined as strength = sum[1] * x - sum[2] * (x - 1) + sum[3] * (x - 2) - sum[4] * (x - 3) + ... + sum[x] * 1 where sum[i] is the sum of the elements in the ith subarray. Formally, strength is sum of (-1)i+1 * sum[i] * (x - i + 1) over all i's such that 1 <= i <= x.

You need to select k disjoint subarrays from nums, such that their strength is maximum.

Return the maximum possible strength that can be obtained.

Note that the selected subarrays don't need to cover the entire array.

 

Example 1:

Input: nums = [1,2,3,-1,2], k = 3
Output: 22
Explanation: The best possible way to select 3 subarrays is: nums[0..2], nums[3..3], and nums[4..4]. The strength is (1 + 2 + 3) * 3 - (-1) * 2 + 2 * 1 = 22.
Example 2:

Input: nums = [12,-2,-2,-2,-2], k = 5
Output: 64
Explanation: The only possible way to select 5 disjoint subarrays is: nums[0..0], nums[1..1], nums[2..2], nums[3..3], and nums[4..4]. The strength is 12 * 5 - (-2) * 4 + (-2) * 3 - (-2) * 2 + (-2) * 1 = 64.
Example 3:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The best possible way to select 1 subarray is: nums[0..0]. The strength is -1.
 

Constraints:

1 <= n <= 104
-109 <= nums[i] <= 109
1 <= k <= n
1 <= n * k <= 106
k is odd.
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        using ll = long long;
        
        int n = nums.size();
        const ll INF = 1e17;
        
        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
        
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -INF));
        
        // for m = 1
        ll min_pref = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][1] = max(dp[i - 1][1], (pre[i] - min_pref) * k);
            min_pref = min(min_pref, pre[i]);
        }
        
        for (int m = 2; m <= k; m++) {
            vector<ll> val(n + 1, -INF);
            for (int j = 1; j <= n; j++) {
                ll p = pre[j - 1] * (k - m + 1) * (m & 1 ? -1 : 1);
                val[j] = max(val[j - 1], dp[j - 1][m - 1] + p);
            }
            
            for (int i = 1; i <= n; i++) {
                ll p = pre[i] * (k - m + 1) * (m & 1 ? 1 : -1);
                dp[i][m] = max(dp[i - 1][m], p + val[i]);
            }
        }
        
        return dp[n][k];
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> nums1 = {1, 2, 3, -1, 2};
    int k1 = 3;
    cout << "Example 1: " << sol.maximumStrength(nums1, k1) << endl; // Output: 22
    
    vector<int> nums2 = {12, -2, -2, -2, -2};
    int k2 = 5;
    cout << "Example 2: " << sol.maximumStrength(nums2, k2) << endl; // Output: 64
    
    vector<int> nums3 = {-1, -2, -3};
    int k3 = 1;
    cout << "Example 3: " << sol.maximumStrength(nums3, k3) << endl; // Output: -1
    
    return 0;
}
