
import heapq

from collections import Counter
def topKFrequent(nums,k):
    c=Counter(nums)
    a=sorted(c.items(),key=lambda p:p[-1],reverse=True)
    return [i for i,j in a[:k]] 


def heapMethod(nums,k):
    c=Counter(nums)
    a=[]
    for _k,v in c.items():
        heapq.heappush(a,(-v,_k))    
    ans=[]
    for _ in range(k):
        _,_v = heapq.heappop(a)
        ans.append(_v)
    return ans    
nums=[1,1,1,2,2,3]
print(topKFrequent(nums,2))
print(heapMethod(nums,2))