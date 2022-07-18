'''
Find the Mode in an Array (Most Frequent Number).
'''
from collections import Counter
from statistics import mode
def modeNumber(nums):
    x=Counter(nums)
    # return max(v for k,v in x.items())
    n=max(x.values())
    for v in nums:
        if n==x[v]:
            return v

nums=[1,2,2,3,3,4,4,4,4]
print(modeNumber(nums))