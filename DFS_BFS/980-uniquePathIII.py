
from functools import lru_cache

def uniquePaths(grid):
    sx,sy=-1,-1
    n=1
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j]==1:
                sx,sy=i,j
            elif grid[i][j]==0:
                n+=1
                
    # @lru_cache(None)  #lru_cache can not be used for list,as it is not hashable type
    def dfs(grid, x,y,n):# x: current row, y:current column, n: the nodes left
        if x<0 or x==len(grid) or y<0 or y==len(grid[0]) or grid[x][y]==-1:
            return 0
        if grid[x][y]==2:
            return n==0
        
        grid[x][y]=-1
        paths=dfs(grid,x,y+1,n-1)+dfs(grid,x,y-1,n-1)+dfs(grid,x-1,y,n-1)+dfs(grid,x+1,y,n-1)
        grid[x][y]=0
        return paths
    return dfs(grid,sx,sy,n)


grid=(((1,0,0,0),(0,0,0,0),(0,0,2,-1)))
print(uniquePaths(grid))


    