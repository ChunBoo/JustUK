

def f():
    l,r=1,2048
    while l<=r:
        m=(l+r)//2
        mm=pow(m,m)
        if mm==pow(2,2048):
            return m
        if mm>pow(2,2048):
            r=m-1
        else:
            l=m+1
            
print(f())