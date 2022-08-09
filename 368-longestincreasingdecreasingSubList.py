
def longestincreasingdecreasingSubList(nums):
    n=len(nums)
    inc=[1]*n
    dec=[1]*n
    
    for i in range(1,n):
        if nums[i]>nums[i-1]:
            inc[i]+=inc[i-1]
            
    for i in range(n-2,-1,-1):
        if nums[i]>nums[i+1]:
            dec[i]+=dec[i+1]
            
    ans=0
    for i in range(2,n-1):
        if inc[i]>1 and dec[i]>1:
            ans=max(ans,inc[i]+dec[i]-1)
            
    return ans

nums=[2,3,1,3,5,3,0,1,3,2,2]
print(longestincreasingdecreasingSubList(nums))