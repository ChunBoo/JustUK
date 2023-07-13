
from collections import deque

def shortestPathLength(g):
    n=len(g)
    kAns=(1<<n)-1
    q=deque()
    visited=[[0]*(1<<n)]*n

    for i in range(n):
        q.append((i,1<<i))

    steps=0
    while len(q)>0 :
        s=len(q)
        while s:
            s-=1
            node, sts=q[0]
            q.popleft()

            if sts==kAns:
                return steps
            if visited[node][sts]:
                continue;
            visited[node][sts]=1
            print("visited node:",node,sts)
            for nxt in g[node]:
                q.append((nxt,sts|1<<nxt))
            # s-=1
        steps+=1
    return -1

g=[[1,2,3],[0],[0],[0]]
print(shortestPathLength(g))
    