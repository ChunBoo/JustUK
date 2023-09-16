def makeConnected(n,connections):
    if len(connections)< n-1:
        return -1
    
    #create graph now
    g=[[] for _ in range(n)]  # the g=[[]] can not work
    
    for c in connections:
        g[c[0]].append(c[1])
        g[c[1]].append(c[0])
    
    seen=set()
    def dfs(cur):
        seen.add(cur)
        for nxt in g[cur]:
            if nxt not in seen:
                seen.add(nxt)
                dfs(nxt)
    count=0
    for i in range(n):
        if i not in seen:
            count+=1
            dfs(i)
    return count-1

n = 4
connections = [[0,1],[0,2],[1,2]]
print(makeConnected(n,connections))