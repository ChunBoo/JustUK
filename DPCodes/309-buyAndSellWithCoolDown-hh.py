class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        @cache
        def dp(i):
            if i<0:
                return -10**9,-10**9,0
            
            sold,hold,cooldown=dp(i-1)
            return (hold+prices[i],
                    max(hold,cooldown-prices[i]),
                    max(cooldown,sold))
        return max(dp(n-1))