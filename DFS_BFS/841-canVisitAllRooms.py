

def canVisitAllRooms(rooms):
    visited=set()
    def dfs(cur):
        if cur in visited:
            return ;
        visited.add(cur)
        for nxt in rooms[cur]:
            dfs(nxt)
    
    dfs(0)
    return len(visited)==len(rooms)

rooms = [[1],[2],[3],[]]
print(canVisitAllRooms(rooms))