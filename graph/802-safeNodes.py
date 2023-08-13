
def  safeNodes(graph):
    n=len(graph)
    states=[0]*n  #0,unknow, 1,safe,-1 unsafe,2 visiting
    ans=[]
    def dfs(cur):
        if states[cur]==2:
            return -1
        if  states[cur]!=0:
            return states[cur]
        
        states[cur]=2
        for nxt in graph[cur]:
            if dfs(nxt)==-1:
                states[nxt]=-1
                return -1
        states[cur]=1
        return 1
    for i in range(n):
        if dfs(i)==1:
            ans.append(i)

    ans.sort()
    return ans

graph = [[1,2],[2,3],[5],[0],[5],[],[]]
print(safeNodes(graph))