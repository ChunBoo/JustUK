from collections import defaultdict,deque


def countPair(n,edges):
    ans=0
    seen=set()
    G=defaultdict(list)
    
    for a,b in edges:
        G[a].append(b)
        G[b].append(a)
        
    def bfs(i):
        if i in seen:
            return 0
        
        q=deque([i])
        a=0
        while q:
            c=q.popleft()
            a+=1
            for v in G[c]:
                if v not in seen:
                    seen.add(v)
                    q.append(v)
        return a
    
    for i in range(n):
        if i not in seen:
            c=bfs(i)
            ans+=(n-c)*c
    return ans//2

n = 7
edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
print(countPair(n,edges))