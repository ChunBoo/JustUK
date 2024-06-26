/***
 * You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:

For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [2,3,6]
Output: 2
Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
Example 2:

Input: nums = [1,4,3]
Output: 2
Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.
 

Constraints:

2 <= nums.length <= 14
1 <= nums[i] <= 109
 */

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        static const int mod = 1e9 + 7;
         int n = nums.size();
        vector<vector<int>> f(1 << n, vector<int>(n, -1));

        function<int(int, int)> dfs = [&](int state, int i) {
            if (f[state][i] != -1) {
                return f[state][i];
            }
            if (state == (1 << i)) {
                return 1;
            }
            f[state][i] = 0;
            for (int j = 0; j < n; j++) {
                if (i == j || !(state >> j & 1)) {
                    continue;
                }
                if (nums[i] % nums[j] != 0 && nums[j] % nums[i] != 0) {
                    continue;
                }
                f[state][i] = (f[state][i] + dfs(state ^ (1 << i), j)) % mod;
            }
            return f[state][i];
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + dfs((1 << n) - 1, i)) % mod;
        }
        return res;

}
};