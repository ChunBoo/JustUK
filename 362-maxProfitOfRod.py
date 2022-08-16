
def maxProfitUnboundedKnapsack(prices,n):  #top2bottom
    
    # @cache
    def dfs(n):
        if n<=0:
            return 0
        
        ans=0
        for i in range(n):
            ans=max(ans,dfs(n-i-1)+prices[i])
        return ans
    
    return dfs(n)


prices=[1, 3, 5, 7, 7, 7]
print(maxProfitUnboundedKnapsack(prices, 6))