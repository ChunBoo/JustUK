

def numTress(n):
    # dp=[0 for i in range(n+1)]
    dp=[0]*(n+1)
    
    dp[0]=1
    dp[1]=1
    
    for i in range(2,n+1):
        for j in range(1,i+1):
            dp[i]+=(dp[i-j]*dp[j-1])
    return dp[n]


print(numTress(3))