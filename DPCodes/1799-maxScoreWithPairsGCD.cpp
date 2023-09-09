/**
 * You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

 

Example 1:

Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1
Example 2:

Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
Example 3:

Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 

Constraints:

1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 106
*/

class Solution {  //top-down method
public:
    int maxScore(vector<int>& nums) {
        const int kSize=nums.size();
        vector<vector<int>> cache(1<<kSize,vector<int>(kSize/2+1));
        function<int(int,int)> dp=[&](int mask,int k){
            if(mask==0) return 0;
            int& ans=cache[mask][k];
            if(ans>0) return ans;

            for(int i=0;i<kSize;++i)
                for(int j=i+1;j<kSize;++j)
                    if((mask&(1<<i))&&(mask &(1<<j)))
                        ans=max(ans,k*gcd(nums[i],nums[j])+dp(mask^(1<<i)^(1<<j),k+1));
            return ans;
        };
        return dp((1<<kSize)-1,1);
    }
};


/*
class Solution {
public:
    int maxScore(vector<int>& nums) {
        const int kSize=nums.size();
        vector<vector<int>> dp(1<<kSize,vector<int>(kSize/2+1));

        for(int mask=0;mask<1<<kSize;++mask){
            int c=__builtin_popcount(mask);
            if(c&1) continue;
            int k=c/2+1;
            for(int i=0;i<kSize;++i)
                for(int j=i+1;j<kSize;++j)
                    if((mask&(1<<i))+(mask&(1<<j))==0){
                        int newMask=mask|(1<<i)||(1<<j);
                        dp[newMask][k]=max(dp[newMask],
                                            k*gcd(nums[i],nums[j])+dp[mask][k-1]);
                    }
        }
        return dp[(1<<kSize)-1][kSize/2];
    }
};
*/
class Solution {
public:
  int maxScore(vector<int>& nums) {
    const int l = nums.size();
    vector<int> dp(1 << l);    
    for (int mask = 0; mask < 1 << l; ++mask) {
      int c = __builtin_popcount(mask);
      if (c & 1) continue; // only do in pairs
      int k = c / 2 + 1;
      for (int i = 0; i < l; ++i)
        for (int j = i + 1; j < l; ++j)
          if ((mask & (1 << i)) + (mask & (1 << j)) == 0) {            
            int new_mask = mask | (1 << i) | (1 << j);            
            dp[new_mask] = max(dp[new_mask],
                               k * gcd(nums[i], nums[j]) + dp[mask]);
        }
    }
    return dp[(1 << l) - 1];
  }
};