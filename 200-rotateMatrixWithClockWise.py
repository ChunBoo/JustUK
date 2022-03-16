
def transpose(A):
    if not A:
        return None

    R,C=len(A),len(A[0])
    
    T=[[0 for _ in range(R)] for _ in range(C)]
    
    for r in range(R):
        for c in range(C):
            T[c][r]=A[r][c]
    
    return T

def rotate(M):
    M[:]=transpose(M)
    
    r=len(M)
    for i in range(r):
        M[i]=M[i][::-1]
    return M

A=[[1,2,3],[4,5,6],[7,8,9]]
R=rotate(A)
print(R)