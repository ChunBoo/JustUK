'''
summary of shortest distance in Graph
  
  dijkstra   weighted      O(E+VLogV)
  floyd      weighted      O(V^3)
  BFS        UnWeighted    O(V+E)
  DFS        UW
  UCS        Weighted
'''
from math import inf
from functools import lru_cache

# def dfs(s,e,seen=set(),d):
#     if s==e:
#         return 0
#     if s in seen:
#         return inf
#     if d<0:
#         return inf
#     seen.add(s)
#     ans=inf
#     for v in G[s]:
#         ans=min(ans,dfs(v,e,seen,d-1)+1)
#     return ans


# def IDS(G,s,e):
#     N=len(G)
#     d=0
#     while d<N:
#         ans=dls(G,s,e,d)
#         if ans<inf:
#             return ans
#         d+=1
#     return inf

def shortestDistance(G,paths):
    @lru_cache
    def ids(i,j):
        N=len(G)+1
        
        def dls(i,j,seen,depth):
            if i==j:
                return 0
            if i in seen:
                return inf
            if depth<0:
                return inf
            
            seen.add(i)
            ans=inf
            for x in G[i]:
                ans=min(ans,dls(x,j,seen,depth-1)+1)
            seen.remove(i)
            return ans
        
        for d in range(N):
            x=dls(i,j,set(),d)
            if x<inf:
                return x
        return 0
    
    return sum(ids(i,j) for i,j in paths)

ports = [
    [2, 3],
    [2],
    [1, 0],
    [4],
    []
]
shipments = [
    [2, 4]
]

print(shortestDistance(ports,shipments))