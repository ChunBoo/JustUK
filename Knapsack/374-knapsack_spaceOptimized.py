

# reviewing DP top-down

from functools import lru_cache
weights=[1,2,3]
values=[1,5,0]
@lru_cache
def dfs(i,c): # i is the index, c is left capacity
    if i<0:
        return 0

    ans=0
    if c>=weights[i]:
        ans=dfs(i-1,c-weights[i])+values[i]
    ans=max(ans,dfs(i-1,c))
    
    return ans


def knapSack01(V,W,C):
    n=len(V)
    dp=[[0 for _ in range(C+1)] for _ in range(n)]
    
    for i in range(C,W[0]-1,-1):
        dp[0][i]=V[0]
        
    for i in range(1,n):
        for j in range(C+1):
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-W[i]]+V[i] if j>=W[i] else 0)
            
    return dp[n-1][C]

print(knapSack01(values,weights,5))

print(dfs(3-1,5))