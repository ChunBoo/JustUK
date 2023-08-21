
from math import inf,sqrt

def closestPrimes(left,right):
    primes=[1]*(right+1)

    primes[0]=primes[1]=0

    for i in range(2,int(sqrt(right))+1):
        if not primes[i]:
            continue
        k=i*i
        while k<right+1:
            primes[k]=0
            k+=i
        # for k  in range(i*i,right+1,k+=i):
        #     primes[k]=0
        #     # k+=i

    
    last,best=-1, inf
    ans=[]
    for i in range(left,right+1):
        if not primes[i]:
            continue
        if last>0 and i-last<best:
            best=i-last
            ans=[last,i]
        
        last=i
    return ans

print(closestPrimes(11,19))