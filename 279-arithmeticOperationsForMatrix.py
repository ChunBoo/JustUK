

def multiplyMatrix(a,b):
    R=len(a)
    assert R>0
    C=len(a[0])
    assert C==len(b)
    M=[[0 for _ in range(len(b[0]))] for _ in range(R) ]
    for i in range(R):
        for j in range(len(b[0])):
            for k in range(C):
                M[i][j]+=a[i][k]*b[k][j]
                
    return M

a=[[1,2,3],[4,5,6],[7,8,9]]
b=[[1,0,0],[0,1,0],[0,0,1]]
print(multiplyMatrix(a,b))