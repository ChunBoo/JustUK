



def maxSquare(m):
    r=len(m)
    c=len(m[0])

    s = [[0 for _ in range(c+1)] for _ in range(r+1)]
    # s = [[0 for i in range(c+1)] for j in range(r+1)]

    for i in range(1,r+1):
        for j in range(1,c+1):
            s[i][j]=m[i-1][j-1]+s[i-1][j]+s[i][j-1]-s[i-1][j-1]

    ans=0
    for i in range(1,r+1):
        for j in range(1,c+1):
            for k in range(min(r-i+1,c-j+1),0,-1):
                tmp=s[i+k-1][j+k-1]-s[i+k-1][j-1]-s[i-1][j+k-1]+s[i-1][j-1]
                if tmp==k*k:
                    ans=max(ans,tmp)
    return ans


# m=[[1,0,1,0,0],
#    [1,0,1,1,1],
#    [1,1,1,1,1],
#    [1,0,0,1,0]]
m=[[1,1,1],
   [1,1,1]]
print(maxSquare(m))           