

def largestSubMatrix(m):
    r=len(m)
    c=len(m[0])
    
    for i in range(c):
        for j in range(1,r):
            m[i][j]+=m[i][j-1]
    ans=0
    for i in range(r):
        m[i].sort(reverse=True)
        for j in range(c):
            sum=0
            sum+=(j+1)*m[i][j]
            ans=max(ans,sum)
    return ans

matrix = [[0,0,1],[1,1,1],[1,0,1]]
print(largestSubMatrix(matrix))