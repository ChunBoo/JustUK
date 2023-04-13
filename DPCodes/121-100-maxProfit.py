'''
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
'''
# https://github.com/Seanforfun/Algorithm-and-Leetcode/blob/master/leetcode/121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock.md
class Solution:
    def maxProfit(self, prices):
        n=len(prices)
        dp=[[0]*2]*(n+1)

        dp[0][0]=-prices[0] #buy
        dp[0][1]=0          #not buy

        for i in range(1,n):
            dp[i][0]=max(-prices[i],dp[i-1][0])
            dp[i][1]=max(dp[i-1][0]+prices[i],dp[i-1][1])
        return dp[n][1]

def maxProfit2(prices):
    n=len(prices)
    minVal=prices[0]
    maxProfit=0
    for i in range(0,n):
        # minVal=min(minVal, prices[i])
        maxProfit=max(prices[i],prices[i]-minVal)
        minVal=min(minVal,prices[i])
    return maxProfit
    

prices = [7,1,5,3,6,4]
print(Solution().maxProfit(prices))
print(maxProfit2(prices))