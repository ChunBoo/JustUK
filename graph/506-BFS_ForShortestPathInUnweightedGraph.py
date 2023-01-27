"""
Breadth First Search Algorithm (BFS) performs a level by level order, and we can use this algorithm to get the shortest path in a unweighted graph. 
The BFS Algorithm uses a Queue which is a First In First Out Data Structure.
Graph is the directed graph
"""

from collections import deque,defaultdict

def BFS(G,s,e):
    if s==e:
        return 0
    q=deque([(0,s)])
    seen=set()
    while q:
        c,v =q.popleft()
        if v==e:
            return c
        if v in seen:
            continue
        seen.add(v)
        for x in G[v]:
            q.append((c+1,x))
    return -1

def shortestDistance(adjacentList,s,e):
    G=defaultdict(list)
    
    for a,b in adjacentList:
        G[a].append(b)
        
    return BFS(G,s,e)


adjancentList=[[1,2],[2,3],[2,4],[1,3],[3,4],[3,5]]

s,e=1,4
print(shortestDistance(adjancentList,s,e))