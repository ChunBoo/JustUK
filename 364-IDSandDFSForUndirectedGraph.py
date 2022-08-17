
#iterative depending searching

def IDS(G):
    def dfs(cur,D,d,G,src,target):# D is the maximum depth,d is current depth
        if src in seen:
            return False
        
        
        if d>D:
            return False
        
        if src==target:
            return True
        seen.add(cur)
        
        for n in G[cur]:
            dfs(n,D,d+1,G,)
            
    found=False
    while not found:
        seen=set()
        found=dfs(s,D,1)
        d+=1
        