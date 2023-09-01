

def possibleBiPartition(n, dislikes):
    g_=[[] for _ in range(n)]  #this method should be pay more attention
    colors=[0]*n

    def dfs(cur,color):
        colors[cur]=color
        for nxt in g_[cur]:
            if colors[nxt]==colors[cur]:
                return False
            if colors[nxt]==0 and not dfs(nxt,-color):
                return False
        return True

    for d in dislikes:
        g_[d[0]-1].append(d[1]-1)
        g_[d[1]-1].append(d[0]-1)
    
    for i in range(n):
        if colors[i]==0 and not dfs(i,1):
            return False
    return True

n = 4
dislikes = [[1,2],[1,3],[2,4]]
print(possibleBiPartition(n,dislikes))
        
