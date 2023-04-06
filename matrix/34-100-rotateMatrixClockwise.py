
def rota(m):
    R=len(m)
    C=len(m[0])
    #transpose
    for r in range(R):
        for c in range(r):
            m[r][c],m[c][r]=m[c][r],m[r][c]
    #swap
    for r in range(R):
        e=C-1;
        for c in range(C//2):
             m[r][c],m[r][e]=m[r][e],m[r][c]
             e-=1
    
    
m=[[1,2,3],
   [4,5,6],
   [7,8,9]]
rota(m)
print(m)