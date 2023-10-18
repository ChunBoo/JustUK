

def minTime(n,edges,apples):
    g=[[] for i in range(n)]
    
    for e in edges:
        g[e[0]].append(e[1])
        g[e[1]].append(e[0])
    seen=set()
    def dfs(cur):
        total=0
        seen.add(cur)   #why we need to add here?
        for c in g[cur]:
            if c in seen:
                continue
            # seen.add(c)
            cost=dfs(c)
            if cost>0 or apples[c]:
                total+=(cost+2)
        return total
    
    return dfs(0)

n = 7
edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
hasApple = [False,False,True,False,True,True,False]
print(minTime(n,edges,hasApple))
    