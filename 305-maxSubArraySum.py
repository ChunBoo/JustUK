
import math
def maxSubArray(nums):
    n=len(nums)
    assert n>0
    dpi=0
    ans=-math.inf
    
    for i in nums:
        dpi=max(i,dpi+i)
        ans=max(ans,dpi)
    
    return ans

nums=[2,3,-10]
print(maxSubArray(nums))