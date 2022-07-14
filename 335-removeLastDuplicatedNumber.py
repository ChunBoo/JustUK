
from collections import Counter,defaultdict
def removeLastDuplicated(nums):
    x=Counter(nums)
    res=[]
    
    last =defaultdict(int)
    for i,v in enumerate(nums):
        last[v]=i
    for i,v in enumerate(nums):
        if x[v]==1 or last[v]!=i:
            res+=[v]
    return res


nums=[1,2,3,2,3,4,5]
res=removeLastDuplicated(nums)
print(res) 