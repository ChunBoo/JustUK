from queue import deque

def visit(n):
    print(n)
    
    
def BFS(G,src,target):
    seen=set()
    
    seen.add(src)
    if src==target:
        return True
    q=deque(src)
    while q:
        cur=q.popleft()
        visit(cur)
        if cur==target:
            return True;
        for n in G[cur]:
            if n not in seen:
                seen.add(n)
                q.append(n)
    return False

G={
    'A':['B','C','D'],
   'B':['E'],
   'C':[],
   'D':['E'],
   'E':['B','D']
   }

print(BFS(G,'A','E'))
