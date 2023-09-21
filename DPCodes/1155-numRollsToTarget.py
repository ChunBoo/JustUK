

def numRollsToTarget(n,f,target):  # n: dices count, f:faces of each dice, target:sum 
    kModule=1e9+7
    dp=[[0]*(target+1) for _ in range(n+1)]
    
    dp[0][0]=1
    for i in range(1,n+1):
        for j in range(1,f+1):
            for k in range(j,target+1):
                dp[i][k]=dp[i][k]+dp[i-1][k-j]
    return dp[n][target]

n,f,target=2,6,7
print(numRollsToTarget(n,f,target))
    
      