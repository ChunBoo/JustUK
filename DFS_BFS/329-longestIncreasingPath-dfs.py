

def longestIncreasingPath(mat):
    R,C=len(mat),len(mat[0])
    if not mat:
        return 0
    
    dp=[[0 for _ in range(C)] for _ in range(R)]

    def dfs(r,c):
        if dp[r][c]:
            return dp[r][c]
        
        dp[r][c]=1
        dirs=[0,-1,0,1,0]

        for i in range(4):
            tr,tc=r+dirs[i],c+dirs[i+1]
            if tr<0 or tc<0 or tr>=R or tc>=C or mat[tr][tc]<=mat[r][c]:
                continue
            dp[r][c]=max(dp[r][c],1+dfs(tr,tc))
        return dp[r][c]
    ans=0
    for r in range(R):
        for c in range(C):
            ans=max(ans,dfs(r,c))
    return ans

matrix = [[9,9,4],[6,6,8],[2,1,1]]
print(longestIncreasingPath(matrix))