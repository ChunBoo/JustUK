class Solution:
    def minPathSum(self, grid):
        m=len(grid)
        n=len(grid[0])
        dp=[[0 for _ in range(n)] for i in range(m)]
        dp[0][0]=grid[0][0]
        for r in range(1,m):
            dp[r][0]=grid[r][0]+dp[r-1][0]
        for c in range(1,n):
            dp[0][c]=grid[0][c]+dp[0][c-1]
        
        for r in range(1,m):
            for c in range(1,n):
                dp[r][c]=min(dp[r-1][c],dp[r][c-1])+grid[r][c]
        return dp[m-1][n-1]
    
grid=[[1,3,1],[1,5,1],[4,2,1]]
print(Solution().minPathSum(grid))