from collections import Counter
from math import gcd
def f(nums):
    C=Counter(nums)
    n=list(C.values())
    a=n[0]
    for i in n:
        a=gcd(a,i)
    return a>1

l=[1,1,2,2,5,5,5]
print(f(l))