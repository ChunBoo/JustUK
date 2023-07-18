

def isUglyNumber(n):
    if n==0:
        return 0
    factors=[2,3,5]
    for f in factors:
        while n%f==0:
            n/=f
    return n==1


for i in [14]:
    print(i,"is ugly number:",isUglyNumber(i))