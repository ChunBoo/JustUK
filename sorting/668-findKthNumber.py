
def LEX(m,n,x):
    cnt=0
    for i in range(1,m+1):
        cnt+=min(n,x//i)
    return cnt

def findKthNumberInMatrix(m,n,k):
    l,r=1,m*n+1
    while l<r:
        x=l+(r-l)//2
        if LEX(m,n,x)>=k:
            r=x
        else:
            l=x+1
    return l


m,n,k=3,3,7

print(findKthNumberInMatrix(m, n, k))