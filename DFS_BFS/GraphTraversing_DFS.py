def visit(n):
    print(n)
    

def DFS(G,node,seen):
    
    # if node in seen:
    #     return 
    visit(node)
    for n in G[node]:
        if n not in seen:
            seen.add(n)
            DFS(G,n,seen)
            

G={
    'A':['B','C','D'],
   'B':['E'],
   'C':[],
   'D':['E'],
   'E':['B','D']
   }
seen=set()
DFS(G,'A',seen)