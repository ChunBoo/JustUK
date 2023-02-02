from collections import defaultdict
from operator import eq
class Solution:
    def equalPairs(self,grid):
        R=defaultdict(int)
        for r in grid:
            R[tuple(r)]+=1
        
        C=defaultdict(int)
        for c in zip(*grid):
            C[tuple(c)]+=1
        
        return sum(R[k]*C[k] for k in R)
    # def equalPairs(self, grid):
    #     d=defaultdict(list)
        
    #     n=len(grid)
    #     for i in range(n):
    #         for k in range(n):
    #             d[i].append(grid[k][i]) 
    #             d[10+i].append(grid[i][k]) #for k in range(n))
    #     ans=0
    #     for i in range(n):
    #         isEqual=True
    #         for j in range(n):
    #             if d[i][j]!=d[i+10][j]:
    #                 isEqual=False
            
    #         if isEqual:
    #             ans+=1
    #     return ans
    
grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
print(Solution().equalPairs(grid))