
# sieve algorithm
def  prime(n):  
    isPrime=[False]*2+[True]*(n-1)
    i=2
    while(i*2<=n):
        if isPrime[i]:
            j=i*2
            while j<=n:
                isPrime[j]=False
                j+=i
        i+=1
    return [x for x in range(2,n+1) if isPrime[x]]


ans=prime(20)
print(ans)
