
from collections import deque,defaultdict
def bfs(r,c,x,m):
    q=deque([(r,c)])  #here is [(r,c)]
    R=len(m)
    C=len(m[0])
    while q:
        rr,cc=q.popleft()
        for dr,dc in ((1,0),(0,1),(-1,0),(0,-1)):
            nr=rr+dr
            nc=cc+dc
            if nr>=0 and nr<R and nc>=0 and nc<C and m[nr][nc]==x:   #condition should add the colors determination
                m[nr][nc]=-1
                q.append((nr,nc))
                

def steps(m):
    if not m:
        return 0
    R,C=len(m),len(m[0])
    data=defaultdict(int)
    for r in range(R):
        for c in range(C):
            if m[r][c]!=-1:
                color=m[r][c]
                bfs(r,c,color,m)
                data[color]+=1
    return sum(data.values())-max(data.values())
matrix = [
    [1, 1, 1, 1],
    [2, 2, 2, 2],
    [1, 3, 1, 2]
]

print(steps(matrix))
