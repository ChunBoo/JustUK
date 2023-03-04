
from collections import deque

def isThereAPath(grid):
    rows=len(grid)
    cols=len(grid[0])
    balance=0
    q=deque([(0,0,balance)])
    seen=set()
    while q:
        r,c,b=q.popleft()
        b+=1 if grid[r][c]==1 else -1
        if r==rows-1 and c==cols-1:
            if b==0:
                return True
        if (r,c) in seen:
            continue
        seen.add((r,c))
        for dr,dc in ((0,1),(1,0)):
            nr,nc=dr+r,dc+c
            if 0<=nr<rows and 0<=nc<cols:
                q.append((nr,nc,b))
    return False
            
        
grid = [[1,1,0],[0,0,1],[1,0,0]]#[[0,1,0,0],[0,1,0,0],[1,0,1,0]]#
print(isThereAPath(grid))