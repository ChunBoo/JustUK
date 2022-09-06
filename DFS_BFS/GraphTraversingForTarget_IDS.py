def visit(n):
    print(n)
    

def DFS(G,node,target,seen,depth,maxDepth):
    
    # if node in seen:
    #     return
    if node in seen:
        return False
    # if depth>maxDepth:
    #     return  False
    seen.add(node)
    visit(node)
    if node==target:
        return True
    
    for n in G[node]:
        if DFS(G,n,target,seen,depth+1,maxDepth):
            return True


G={
    'A':['B','C','D'],
   'B':['E'],
   'C':[],
   'D':['E'],
   'E':['B','D']
   }

            
def ids(G, src, target):
   found = False
   depth=0
   while not found:
       seen = set()
       depth += 1
       found = DFS(G, src, target, seen, 0, depth)   

ids(G,'A','E')