# from cv2 import accumulate
import numpy

def countIsland(M):
    if not M:
        return 0
    rows,cols=len(M),len(M[0])
    
    def dfs(r,c):
        if r<0 or c<0 or r>=rows or c>=cols:
            return 
        M[r][c]=0
        dfs(r,c-1)
        dfs(r,c+1)
        dfs(r-1,c)
        dfs(r+1,c)
        
        # for dx,dy in ((0,-1),(0,1),(-1,0),(1,0)):
        #     m[r+dx][c+dy]=0
            
    #check border
    # for r in range(rows):
    #     for c in range(cols):
    #         if r==0 or r==rows-1 or c==0 or c==cols-1:
    #             dfs(r,c)
                
    for r in range(rows):
        
        dfs(r,0)
        dfs(r,cols-1)
        
    for c in range(cols):
        dfs(0,c)
        dfs(rows-1,c)
        
    #for the island inside
    ans=0
    for r in range(1,rows-1):
        for c in range(1,cols-1):
            if M[r][c]:
                dfs(r,c) 
                ans+=1
            
    return ans


m=[[1,1,0,0,1],[0,0,0,1,0,1],[0,0,0,0,0],[1,0,0,0,1]]
# print(countIsland(m))

a=[1,2,3,4,5,6]
s=list(numpy.add.accumulate(a))
print(s)