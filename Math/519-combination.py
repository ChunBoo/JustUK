
from functools import lru_cache


def cc(n,m):
    if m>n:
        return 0
    if m==0 or m==n:
        return 1
    dp=[[0]*(m+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0]=1
    for i in range(m+1):
        dp[i][i]=1
    for i in range(1,n+1):
        for j in range(1,min(i,m)):
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
    return dp[-1][-1]

@lru_cache
def c(n,m):  #top-down dp
    if m>n:
        return 0
    if m==n:
        return 1
    if m==0:
        return 1
    return c(n-1,m)+c(n-1,m-1)


print(c(3,2))
print(cc(3,2))