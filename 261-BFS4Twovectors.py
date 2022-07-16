from collections import defaultdict,deque
def  pathExists(start,end,edges):
    G=defaultdict(list[int])
    for s,e in edges:
        G[s].append(e)
        G[e].append(s)
    q=deque([start])
    seen=set()
    while q:
        c=q.popleft()
        if c==end:
            return True
        if c in seen:
            continue
        seen.add(c)
        for i in G[c]:
            q.append(i)
    return False

# print(pathExists(1,5,[(1,2),[2,3],[2,4]]))
q=deque([3,2])
print(q.popleft())
print(q)