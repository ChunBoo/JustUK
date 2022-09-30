
from collections import defaultdict

from collections import defaultdict
from heapq import heappop, heappush


def shortestGraph(edges,s,e):
    G=defaultdict(list)
    
    for a,b,c in edges:
        G[a]+=[(b,c)]
        
    q=[(0,s)]
    seen=set()
    while q:
        d,cur=heappop(q)
        if cur==e:
            return d
        if cur in seen:
            continue
        for n,c in G[cur]:
            heappush(q,(d+c),n)
            
    return -1