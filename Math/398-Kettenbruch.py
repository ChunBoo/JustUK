#连分数
from functools import lru_cache

def f(a,n):
    if n==0:
        return a/(a+1)
    
    return a/(a+f(a,n-1))


def g(a,n):
    ans=0;
    for _ in range(n):
        ans=a/(a+ans)
    return ans
print(f(1,50))
print(g(1,50))