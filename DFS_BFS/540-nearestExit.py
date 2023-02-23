#unweighted,undirected can use BFS
from collections import deque
from math import inf
class Solution:
    def nearestExit(self, maze, entrance):
        rows=len(maze)
        cols=len(maze[0])
        def isExit(r,c):
            if r==0 or c==0 or r==rows-1 or c==cols-1:
                return maze[r][c]=='.'
            return False
        q=deque([(entrance,0)])
        seen=set()
        
        while q:
            (r,c),d=q.popleft()
            if (r,c)!=tuple(entrance) and isExit(r, c):
                return d
            for dr,dc in ((0,1),(1,0),(0,-1),(-1,0)):
                nr,nc=r+dr,c+dc
                if nr<0 or nc<0 or nr>=rows or nc>=cols or (nr,nc) in seen:
                    continue
                if maze[nr][nc]=='.':
                    seen.add((nr,nc))
                    q.append(((nr,nc),d+1))
        return -1
    
maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]
entrance = [1,2]

print(Solution().nearestExit(maze, entrance))