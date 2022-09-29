

def f(n,m):
    if n==1:
        return 0
    if m>0 and n&1==0:
        return 1+f(n//2,m-1)
    if m==0:
        return n-1
    if m>0 and n&1:
        return 1+f(n-1,m)


def f2(n,m):
    ans=0
    while n>1 and m>0:
        if n&1:
            n-=1
        else:
            n//=2
            m-=1
        ans+=1
    return n-1+ans    
    
print(f(15,10))
print(f2(15,4))