"""
You are given an array of n elements. Element at index i represents a stock value on ith day.
You are required to print the maximum profit you can make if you are allowed infinite transactions, 
but we have a cooldown period for 1 day between selling stock and buying new stock.
It means that if we had sold a stock yesterday, then we cannot buy the new stock today,
we will have to remain in a cooldown state for 1 day and hence can buy new stock tomorrow (or any day after tomorrow) only.
Hence, you cannot buy on the next day after you sell, you have to cooldown for a day at-least before buying again.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) 
before opening another transaction (another buy). We cannot first buy 2 stocks and then sell them, i.e. states like "BBSS" are not allowed

Nobody will laugh at you, if you didn't know this! It is very trivial, but still, 
I want to let you know that you cannot sell a stock before buying it! You cannot have a state "SB".
"""


from functools import cache
class Solution:
    def maxProfit(self, prices):# List[int]) -> int:
        '''
        return three values:
        1. maxProfit after selling all stocks ends with i-th day, can not buy and sell
        2. maxprofit with current holding stocks, can sell
        3. maxProfit with cooldown state, can buy
        '''
        @cache
        def dp(i):
            if i<0:
                return -10**9,-10**9,0
            sell,hold,cooldown=dp(i-1)
            return ( hold+prices[i],
                    max(hold,cooldown-prices[i]),
                    max(sell,cooldown))
        return max(dp(len(prices)-1))
    
prices=[1,2,3,0,2]
print(Solution().maxProfit(prices))