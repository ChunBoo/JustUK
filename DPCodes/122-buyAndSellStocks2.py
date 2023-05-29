from functools import cache
class Solution:
    def maxProfit(self, prices):#List[int]) -> int:
        n=len(prices)
        @cache
        def dp(i):
            if i<0:
                return 0,-10**9 #maxProfit, balance
            profit, balance=dp(i-1)
            return max(profit, balance+prices[i]), max(balance, profit-prices[i])
        return dp(n-1)[0]
prices = [7,1,5,3,6,4]
print(Solution().maxProfit(prices))