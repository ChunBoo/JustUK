

def subSetSum(nums):
    total=sum(nums)
    if total&1:
        return False
    
    half=total//2
    
    #@cache
    def dp(i,s):
        if i==len(nums):
            return s==0
        if s<0:
            return False
        
        return dp(i+1,s-nums[i]) or dp(i+1,s)
    
    return dp(0,0)

nums=[1,5,5,11]
print(subSetSum(nums))