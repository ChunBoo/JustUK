class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n=len(prices)
        @cache
        def dp(i):
            if i<0:
                return 0,-10**9
            profit,balance=dp(i-1)
            return max(profit,balance+prices[i]-fee),max(balance,profit-prices[i])
        return dp(n-1)[0]