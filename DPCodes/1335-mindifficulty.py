
from math import inf

def minDifficulty(jobs,d):
    n=len(jobs)
    dp=[[inf//2]*(d+1)]*(n+1)

    dp[0][0]=0
    for i in range(1,n+1):
        for k in range(1,d+1):
            md=0
            for j in range(i-1,k-2,-1):
                md=max(md,jobs[j])
                dp[i][k]=min(dp[i][k],dp[j][k-1]+md)
    return dp[n][d]



jobs=[6,8,4,3,2,1]
d=2

print(minDifficulty(jobs, d))