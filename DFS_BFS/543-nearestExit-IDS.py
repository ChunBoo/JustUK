
def nearestExit(m,entry):
    rows=len(m)
    cols=len(m[0])
    
    def isExit(r,c):
        if r==0 or c==0 or r==rows-1 or c==cols-1:
            return m[r][c]=='.'
        return False
    
    def DLS(pos,d):
        if isExit(pos[0],pos[1]) and pos!=tuple(entry):
            return True
        # if pos in seen:
        #     return False
        if d<=0:
            return False
        # seen.add(pos)
        r,c=pos
        m[r][c]='+'
        for dr,dc in ((0,1),(1,0),(-1,0),(0,-1)):
            nr,nc=dr+r,dc+c
            # r,c=pos
            #nr,nc=dr+r,dc+c
            if 0<=nr<=rows-1 and 0<=nc<=cols-1 and m[nr][nc]=='.' :
                if DLS((nr,nc),d-1):
                    return True
        # seen.remove(pos)
        m[r][c]='.'
        return False
            
    d=0
    D=rows*cols
    seen=set()
    while d<D:
        if DLS(tuple(entry),d):
            return d
        d+=1
    return -1
'''    
class Solution:
    def nearestExit(self, maze,entrance): 
        rows = len(maze)
        assert rows > 0
        cols = len(maze[0])
        assert cols > 0
        
        # @cache
        def isExit(r, c):
            if r == 0 or c == 0 or r == rows - 1 or c == cols - 1:
                return maze[r][c] == '.'
            return False

        def dls(r, c, d):
            if (r, c) != tuple(entrance) and isExit(r, c):
                return True
            if d <= 0:
                return False
            maze[r][c] = "+"
            for dr, dc in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and maze[nr][nc] == '.':                    
                    if dls(nr, nc, d - 1):
                        return True
            maze[r][c] = "."
            return False

        d = 0
        D = rows * cols
        while d < D:
            if dls(entrance[0], entrance[1], d):
                return d
            d += 1
        
        return -1
'''
maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]
entrance = [1,2]

print(nearestExit(maze, entrance))