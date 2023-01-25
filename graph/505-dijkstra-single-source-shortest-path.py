# https://www.geeksforgeeks.org/heap-queue-or-heapq-in-python/
# bfs can be used in 
# dijkstra used in weighted graph
from collections import defaultdict
from math import inf
import heapq
def dijkstra(edges,s,e):
    G = defaultdict(list)
    N = 0
    for a, b, w in edges:
        G[a] += [(b, w)]
        N = max(N, a, b)
    N += 1
    d=defaultdict(lambda: inf)    #https://stackoverflow.com/questions/42137849/defaultdict-first-argument-must-be-callable-or-none
    d[s]=0
    q=[(0,s)]
    seen=set()
    while q:
        c,v=heapq.heappop(q)
        if v in seen:
            continue
        seen.add(v)
        for x,w in G[v]:
            if c+w<d[x]:
                d[x]=c+w
                heapq.heappush(q,(c+w,x))
                
    return d[e]


edges = [
    [0, 1, 3],
    [1, 2, 12],
    [0, 2, 9]
]
start = 0
end = 2

print(dijkstra(edges,start,end))
    