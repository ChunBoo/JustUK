
# from collections import defaultdict

from collections import defaultdict
from heapq import heappop, heappush
# from tkinter import E


def shortestGraph(edges,s,e):  #uniform cost search
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
            heappush(q,(d+c,n))
            
    return -1

def heapSort(iterable):
    h=[]
    for val in iterable:
        heappush(h,val)
    return [heappop(h) for i in range(len(h))]

edges=[
    [0,1,3],
    [1,2,2],
    [0,2,9]
]

# print(shortestGraph(edges,0,2))
print(heapSort([1,3,5,7,9,2,4,6,8,0]))