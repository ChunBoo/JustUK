


def knapsack01(v,w,c):
    n=len(v)
    
    dp=[[0 for _ in range(c+1)] for _ in range(n)]
    
    for i in range(c+1):
        dp[0][i]=0 if i<w[0] else v[0]
        
    
    for i in range(1,n):
        for j in range(c+1):
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i] if c>=w[i] else 0)
    return dp[n-1][c]

weights=[1,2,3]
values=[1,5,3]
print(knapsack01(values,weights,5))