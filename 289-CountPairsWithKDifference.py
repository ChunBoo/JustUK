#绝对差值为K的数组对
from collections import defaultdict
from typing import Counter


def  countPairs(a,k):
    n=len(a)
    ans=0
    
    for i in range(n):
        for j in range(i,n):
            if(abs(a[i]-a[j]))==k:
                ans+=1
                
    return ans


def countPairsCounter(a,k):
    c=Counter(a)
    ans=0
    for i in c:
        ans+=c[i]*c[i+k]
        
    return ans

def  countPairsMap(a,k):
    c=defaultdict(int)
    ans=0
    for i in a:
        ans+=c[i-k]
        ans+=c[i+k]
        c[i]+=1
    return ans

a=[1,2,2,1]
# print(countPairsCounter(a,1))
print(countPairsMap(a,1))