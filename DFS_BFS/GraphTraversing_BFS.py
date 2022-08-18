from queue import deque
def visit(node):
    print(node)

def BFS(G,src):
    q=deque([src])
    seen=set()
    while q:
        cur=q.popleft()
        visit(cur)
        for n in G[cur]:
            if n not in seen:
                seen.add(n)
                q.append(n)
                
G={
    'A':['B','C','D'],
   'B':['E'],
   'C':[],
   'D':['E'],
   'E':['B','D']
   }

BFS(G,'A')