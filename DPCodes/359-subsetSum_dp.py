from functools import lru_cache
# https:/partition-equal-subset-sum/
#416
def subSetSum(nums):
    total=sum(nums)
    sz=len(nums)
    if(total&1):
        return False
    half=total//2
    @lru_cache()
    def  dp(idx,left):
        if(idx==sz):
            return left==0
        if left<0:
            return False
        return dp(idx+1,left-nums[idx]) or dp(idx+1,left)
    return dp(0,half)
nums=[1,5,6,11]
print(subSetSum(nums))