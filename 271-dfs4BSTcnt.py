

def G(n): #TOP2Down
    if n==0 or n==1:
        return 1
    return sum(G(i)*G(n-i-1) for i in range(n))

def B2TG(n):
    G=[0]*(n+1)
    G[0]=1
    for i in range(n+1):  # nodes
        for j in range(i): #which node is root
            G[i]+=G[j]*B2TG(i-j-1)
    return G[n]

print(B2TG(3))


