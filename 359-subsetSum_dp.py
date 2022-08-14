
# https:/partition-equal-subset-sum/
#416
def subSetSum(nums):
    total=sum(nums)
    if total&1:
        return False    
    #@cache
    def dp(i,s):
        if i==len(nums):
            return s==0
        if s<0:
            return False
        
        return dp(i+1,s-nums[i]) or dp(i+1,s)
    
    return dp(0,total//2)

nums=[1,5,5,11]
print(subSetSum(nums))