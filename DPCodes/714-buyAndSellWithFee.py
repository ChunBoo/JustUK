"""
    Given an array of positive integers containing the price of stocks and transaction fee, the task is to find the maximum profit and the difference of days on which you are getting the maximum profit. 

Examples: 

Input: arr[] = {6, 1, 7, 2, 8, 4}
      transactionFee = 2
Output: 8 1

Input: arr[] = {7, 1, 5, 3, 6, 4}
       transactionFee = 1
Output: 5 1
"""

from functools import cache
class Solution:
    def maxProfit(self, prices,fee): #List[int], fee: int) -> int:
        n=len(prices)
        @cache
        def dp(i):
            if i<0:
                return 0,-10**9
            profit, balance=dp(i-1)
            return max(profit,balance+prices[i]-2),max(balance,profit-prices[i])
        return dp(len(prices)-1)[0]
    

prices=[6, 1, 7, 2, 8, 4]   
fee=2
print(Solution().maxProfit(prices, fee))
