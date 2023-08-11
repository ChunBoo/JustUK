
def swapChars(s,si,di):
    t=list(s)
    t[si],t[di]=t[di],t[si]
    return "".join(t)
def slidingPuzzle(board):
    kRows,kCols=len(board),len(board[0])

    start,goal="",""

    for i in range(kRows):
        for j in range(kCols):
            start+=chr(board[i][j])
            goal+=chr((i*kCols+j+1)%(kCols*kRows))
    
    visited=set(start)
    q=[start]
    steps=0
    dirs=[[0,1],[0,-1],[-1,0],[1,0]]
    while q:
        steps+=1
        kSize=len(q)
        while kSize:
            s=q[0]
            q.pop(0)  #if no index, then pop the last element
            p=s.find(chr(0))
            r,c=p//kCols,p%kCols
            for dr,dc in dirs:
                nr=r+dr
                nc=c+dc
                if nr<0 or nc<0 or nr>=kRows or nc>=kCols:
                    continue
                pp=nr*kCols+nc
                t=swapChars("".join(s),p,pp)
                if t in visited:
                    continue
                if t==goal:
                    return steps
                visited.add(t)
                q.append(t)
            kSize-=1
    return -1


board=[[4,1,2],[5,0,3]]
print(slidingPuzzle(board))



