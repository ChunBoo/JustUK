

def  f(rooms):
    seen=set()
    def dfs(room):
        if room in seen:
            return
        seen.add(room)
        for  key in rooms[room]:
            dfs(key)
    dfs(0)
    return len(seen)==len(rooms)



def bfs(rooms):
    q=deque([0])
    seen=set()
    while q:
        room=q.popleft()
        if room in seen:
            continue
        seen.add(room)
        for key in rooms[room]:
            q.append(key)
            
            
            
    return len(seen)==len(rooms)

