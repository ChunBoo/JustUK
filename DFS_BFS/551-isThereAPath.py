'''
given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to 
any of the cells (row + 1, col) or (row, col + 1). Return true if there is a path from (0, 0) to (m – 1, n – 1) 
that visits an equal number of 0’s and 1’s. Otherwise return false.
'''

def isThereAPath(grid):
    balance=0
    rows=len(grid)
    cols=len(grid[0])
    
    def dfs(r,c,b):
        b+=1 if grid[r][c]==1 else -1
        if r==rows-1 and c==cols-1:
            return b==0
        
        # if grid[r][c]==0:
        #     b-=1
        # else:
        #     b+=1
        '''
        if r+1<rows and dfs(r+1,c,b):
            return True
        if c+1<cols and dfs(r,c+1,b):
            return True
        return False
        '''
        for dr,dc in ((1,0),(0,1)):    
            nr,nc=r+dr,c+dc
            if 0<=nr<rows and 0<=nc<cols:
                if dfs(nr,nc,b):
                    return True
        return False
    return dfs(0,0,balance)
    # return False

grid = [[0,1,0,0],[0,1,0,0],[1,0,1,0]]#[[1,1,0],[0,0,1],[1,0,0]]#
print(isThereAPath(grid))