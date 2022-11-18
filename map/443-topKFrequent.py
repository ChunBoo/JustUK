


from collections import Counter
def topKFrequent(nums,k):
    c=Counter(nums)
    a=sorted(c.items(),key=lambda p:p[-1],reverse=True)
    return [i for i,j in a[:k]] 


def heapMethod(nums,k):
    c=Counter(nums)
    a=[]
    for k,v in c.items():
        heappush(a,(-v,k))        
nums=[1,1,1,2,2,3]
print(topKFrequent(nums,2))