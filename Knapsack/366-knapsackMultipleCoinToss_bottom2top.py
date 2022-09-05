


def coins(p,k):
    n=len(p)
    if k>n:
        return 0
    
    f=[[0 for _ in range(k+1)] for _ in range(n)]
    
    f[0][0]=1-p[0]
    f[0][1]=p[0]
    
    for i in range(1,n):      #number of coins
        for j in range(k+1):  #number of heads
            f[i][j]=p[i]*f[i-1][j-1]+(1-p[i])*f[i-1][j]
            
    return f[n-1][k]


prob = [0.5,0.5,0.5,0.5,0.5]
print(coins(prob,5))