"""
 a two-dimensional integer matrix, find the length of the longest strictly increasing path. You can move up, down, left, or right.

Constraints1
n, m ≤ 500 where n and m are the number of rows and columns in matrix
Example 1
Input

1
2
3
4
5
matrix = [
    [1, 3, 5],
    [0, 4, 6],
    [2, 2, 9]
]
Output
6

Explanation
The longest path is [0, 1, 3, 5, 6, 9]

Due to the strictly increasing condition, there cannot be any cycles
Question yourself on what will be the longest increasing path if I start from each cell (consider each cell as a starting point and traverse)
Keep a track of the longest increasing path from each cell. Compute this value once and use it whenever required.
"""
from functools import lru_cache
def longestIncreasingPath(nums):
    rows=len(nums)
    if not rows:
        return 0
    cols=len(nums[0])
    if not cols:
        return 0
   
    @lru_cache
    def f(r,c):
        ans=1
        for dr,dc in ((1,0),(0,1),(-1,0),(0,-1)):
            nr=r+dr
            nc=c+dc
            if 0<=nr<rows and 0<=nc<cols and nums[r][c]<nums[nr][nc]:
                ans=max(ans,1+f(nr,nc))
                
        return ans
    
    ans=1
    for r in range(rows):
        for c in range(cols):
            ans=max(ans,f(r,c))
    return ans
matrix = [
    [1, 3, 5],
    [0, 4, 6],
    [2, 2, 9]
]
print(longestIncreasingPath(matrix))