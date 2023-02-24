
from math import inf

def nearestExit(maze,entry):
    ans=inf
    rows=len(maze)
    cols=len(maze[0])
    def isExit(r,c):
        if r==0 or c==0 or r==rows-1 or c==cols-1:
            return maze[r][c]=='.'
        return False
    def dfs(r,c,d,seen):
        if isExit(r,c) and (r,c)!=tuple(entry):
            nonlocal ans
            ans=min(ans,d)
            return True
        if (r,c) in seen:
            return False
        
        seen.add((r,c))
        
        for dr,dc in ((0,1),(1,0),(-1,0),(0,-1)):
            nr,nc=dr+r,dc+c
            if nr>=0 and nr<=rows-1 and nc>=0 and nc<=cols-1 and maze[nr][nc]=='.':
                dfs(nr,nc,d+1,seen)
        seen.remove((r,c))
    seen=set()
    dfs(entry[0],entry[1],0,seen)
     
    return ans if ans<inf else -1

maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]
entrance = [1,2]

print(nearestExit(maze, entrance))