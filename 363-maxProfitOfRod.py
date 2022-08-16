
def maxProfit(n,prices):
    dp=[0]*(n+1)
    for i in range(n+1):
        for j in range(i):
            dp[i]=max(dp[i],dp[i-j-1]+prices[j])
            
    return dp[n]


prices=[1, 3, 5, 7, 7, 7]
print(maxProfit(6,prices))
for i in range(5):
    print(i)