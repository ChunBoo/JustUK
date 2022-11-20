
from collections import defaultdict
class Solution:
    def solve(self,matrix):
        if not matrix:
            return 0
        
        rows=len(matrix)
        data=defaultdict(int)
        cols=len(matrix[0])
        
        def dfs(r,c,x):
            if r<0 or c<0 or r>=rows or c>=cols:
                return 
            if matrix[r][c]!=x:
                return 
            matrix[r][c]=-1
            dfs(r-1,c,x)
            dfs(r+1,c,x)
            dfs(r,c-1,x)
            dfs(r,c+1,x)
            
        for r in range(rows):
            for c in range(cols):
                if matrix[r][c]!=-1:
                    color=matrix[r][c]
                    dfs(r,c,color)  #must be color here
                    data[color]+=1
        return sum(data.values())-max(data.values())
    
matrix = [
    [1, 1, 1, 1],
    [2, 2, 2, 2],
    [1, 3, 1, 2]
]


print(Solution().solve(matrix))