
def resetMatrix(m):
    R,C=len(m),len(m[0])
    r,c=set(),set()
    
    for i in range(R):
        for j in range(C):
            if(m[i][j]==0):
                r.add(i)
                c.add(j)
                
    for i in range(R):
        for j in range(C):
            if(i in r or j in c ):
                m[i][j]=0
                

m=[[0,0,1],[1,0,1],[1,1,1]]
resetMatrix(m)
print(m)