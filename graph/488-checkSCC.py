from collections import defaultdict

def checkSCC(n,edges):
    
    def check(cur,G):
        seen=set()
        
        def dfs(cur):
            if cur in seen:
                return
            seen.add(cur)
            for i in G:   #G[1]={2,3,4}
                dfs(i)
        dfs(cur)
        return len(seen)==n
    G=defaultdict(list)
    for a,b in edges:
        G[a].append(b) 
    ReversedG=defaultdict(list)
    for a,b in edges:
        ReversedG[b]=a
    
    return check(0,G) and check(0,ReversedG)          

n=2
roads=[[1,0],[0,1]]

print(checkSCC(n,roads))