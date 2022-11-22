
from collections import deque,defaultdict
def bfs(r,c,x,m):
    R,C=len(m),len(m[0])
    q=deque([(r,c)])  #here should be tuple
    while q:
     r,c=q.popleft()
     for dr,dc in ((1,0),(-1,0),(0,1),(0,-1)): #not in range 
        rr=r+dr
        cc=c+dc   
        if 0<=rr<R and 0<=cc<C and m[rr][cc]==x:  #here should add the color condition
            m[rr][cc]=-1
            q.append((rr,cc))
                     

def steps(m):
    if not m:
        return 0
    R=len(m)
    C=len(m[0])
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
