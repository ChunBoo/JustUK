from disjointSet import DisjointSet

def EdgesPathExisted(edges,start,to):
    n=5
    ds=DisjointSet(n+1)
    for s,e in edges:
        ds.merge(s,e)
    return ds.sameGroup(start,to)

edgeslist=[[1,2],[2,3],[3,4]]
print(EdgesPathExisted(edgeslist,1,5))