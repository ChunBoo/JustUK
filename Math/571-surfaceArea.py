'''
You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. Each value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).

After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.

Return the total surface area of the resulting shapes.

Note: The bottom face of each shape counts toward its surface area.
'''

class Solution:
    def surfaceArea(self, grid) :
        n=len(grid)
        ans=0
        for r in range(n):
            for c in range(n):
                if grid[r][c]:
                    ans+=(grid[r][c]*4+2)
                if r>0:
                    ans-=min(grid[r][c],grid[r-1][c])*2
                if c>0:
                    ans-=min(grid[r][c],grid[r][c-1])*2
        return ans
    
g=[[1,2],[3,4]]
print(Solution().surfaceArea(g))