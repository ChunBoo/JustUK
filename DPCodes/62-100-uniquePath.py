def uniquePaths(m,n):
    dp=[[0 for i in range(n)] for j in range(m) ]
    for i in range(n):
        dp[0][i]=1
    for j in range(m):
        dp[j][0]=1
    for r in range(1,m):
        for c in range(1,n):
            dp[r][c]=dp[r-1][c]+dp[r][c-1]
    return dp[m-1][n-1]

print(uniquePaths(3, 7))