
from math import inf

def panlindromeStringsIII(s,K):
    N=len(s)
    cost=[[0]*N]*N
    
    def minCost(i,j):
        cnt=0
        while s[i]!=s[j]:
            cnt+=1
            i+=1
        return cnt
    
    for i in range(N-1):
        for j in range(i+1,N):
            cost[i][j]=minCost(i,j)
            
    
    dp=[[inf//2]*(K+1)]*N
    
    for i in range(N):
        dp[i][1]=cost[0][i]
        for k in range(2,K+1):
            for j in range(i):
                dp[i][k]=min(dp[i][k-1],dp[j][k-1]+cost[j+1][i])
    return dp[N-1][K]


s="ab"
K=2
print(panlindromeStringsIII(s,K))
        