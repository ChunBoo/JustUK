/***
 * You are given an integer array nums of length n, and a positive integer k.

The power of a 
subsequence
 is defined as the minimum absolute difference between any two elements in the subsequence.

Return the sum of powers of all subsequences of nums which have length equal to k.

Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4], k = 3

Output: 4

Explanation:

There are 4 subsequences in nums which have length 3: [1,2,3], [1,3,4], [1,2,4], and [2,3,4]. The sum of powers is |2 - 3| + |3 - 4| + |2 - 1| + |3 - 4| = 4.

Example 2:

Input: nums = [2,2], k = 2

Output: 0

Explanation:

The only subsequence in nums which has length 2 is [2,2]. The sum of powers is |2 - 2| = 0.

Example 3:

Input: nums = [4,3,-1], k = 2

Output: 10

Explanation:

There are 3 subsequences in nums which have length 2: [4,3], [4,-1], and [3,-1]. The sum of powers is |4 - 3| + |4 - (-1)| + |3 - (-1)| = 10.

 

Constraints:

2 <= n == nums.length <= 50
-108 <= nums[i] <= 108 
2 <= k <= n
 */


class Solution {
public:
    using umap=unordered_map<int,int>;
    static constexpr int mod=1e9+7;
    static constexpr int inf=0x3f3f3f3f;
    int sumOfPowers(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;
        vector<vector<umap>> d(n,vector<umap>(k+1));

        sort(begin(nums),end(nums));

        for(int i=0;i<n;i++){
            d[i][1][inf]=1;
            for(int j=0;j<i;j++){
                int diff=abs(nums[i]-nums[j]);
                for(int p=2;p<=k;p++){
                    for(auto &[v,cnt]:d[j][p-1]){
                        d[i][p][min(diff,v)]=(d[i][p][min(diff,v)]+cnt)%mod;
                    }
                }
            }
            for(auto &[v,cnt]:d[i][k]){
                res=(res+1ll*v*cnt%mod)%mod;
            }
            
        }
        return res;
    }
};