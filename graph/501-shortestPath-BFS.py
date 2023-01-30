#BFS only works for directed unweighted graph
from collections import deque,defaultdict
from math import inf
def shortestPath(G,paths):
    #Below codes is unused now
    # n=len(G)
    # d=[[0 if i==j else inf for i in range(n)] for j in range(n)]
    
    # for i,v in enumerate(G):
    #     for j in v:
    #         d[i][j]=1
    # g=defaultdict(list)
    # for i,v in enumerate(G):
    #     for j in v:
    #         g[i].append(j)
    #Above codes are unused now
    def bfs(i,j):
        if i==j:
            return 0
        q=deque([i])
        d=0
        seen=set()
        while q:
            d+=1
            n=len(q)
            for _ in range(n):
                c=q.popleft()
                if c==j:
                    return d-1
                for x in G[c]:
                    if x not in seen:
                        seen.add(x)
                        q.append(x)
        return 0
    return bfs(shipments[0][0],shipments[0][1])

ports = [
    [2, 3],
    [2],
    [1, 0],
    [4],
    []
]
shipments = [
    [2, 3]
]
print(shortestPath(ports,shipments))