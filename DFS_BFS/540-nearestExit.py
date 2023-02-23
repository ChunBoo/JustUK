#unweighted,undirected can use BFS
from collections import deque
from math import inf
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        rows=len(maze)
        cols=len(maze[0])
        def isExit(r,c):
            if r==0 or c==0 or r==rows-1 or c==cols-1:
                return maze[r][c]=='.'
            return False
        q=deque([(entrance,0)])
        seen=set()
        ans =inf
        while q:
            (r,c),d=q.popleft()
            if (r,c)!=tuple(entrance) and isExit(r,c):
                return d
            for dr,dc in ((0,1),(1,0),(0,-1),(-1,0)):
                nr,nc=dr+r,dc+c
                if (nr, nc) in seen or nr < 0 or nc < 0 or nr == rows or nc == cols:
                    continue
                if maze[nr][nc] == '.':
                    q.append(((nr,nc),1+d))
                    seen.add((nr,nc))
        return -1 