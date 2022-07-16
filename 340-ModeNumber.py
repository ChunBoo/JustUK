
from collections import Counter
from statistics import mode
def modeNumber(nums):
    x=Counter(nums)
    # return max(v for k,v in x.items())
    return max(x.values())

nums=[1,2,2,3,3,3,4]
print(modeNumber(nums))