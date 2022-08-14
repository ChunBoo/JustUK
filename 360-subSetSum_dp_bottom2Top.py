

def  subsetSum(nums):
    total=sum(nums)
    if total&1:
        return False
    n=len(nums)
    half=total//2
    dp=[[False for _ in range(half+1)] for _ in range(n+1)]
    
    for i in range(n):
        dp[i][0]=True
        
    for i in range(n-2,-1,-1):
        for j in range(half,-1,-1):
            if j<nums[i]:
                dp[i][j]=dp[i+1][j]
            else:
                dp[i][j]=dp[i+1][j] or dp[i+1][j-nums[i]]
    return dp[0][half]

nums=[1,5,5,11]
print(subsetSum(nums))