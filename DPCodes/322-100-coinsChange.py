'''
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:
Input: coins = [2], amount = 3
Output: -1
Example 3:
Input: coins = [1], amount = 0
Output: 0
'''
from math import inf
class Solution:
    def coinChange(self, coins, amount):
        # ans=0
        # coins.sort(reverse=True)
        # for c in coins:
        #     cur=amount//c
        #     ans+=cur
        #     amount-=c*cur
        #     if amount==0:
        #         return ans
        # return -1 if amount>0 else ans
        if amount<=0:
            return 0
        dp=[inf for _ in range(amount+1)]
        dp[0]=0
        for i in range(1,amount+1):
            for j in coins:
                if j<=i:
                    dp[i]=min(dp[i-j]+1,dp[i])
                else:
                    break
        return dp[-1] if dp[-1]!=inf else -1
coins = [1,5,10,11]
amount = 12
print(Solution().coinChange(coins, amount))