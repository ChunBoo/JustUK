
from functools import cache
def canJump(nums):#dfs method
    n=len(nums)
    @cache
    def dfs(cur):
        if cur>=n-1:
            return True
        for i in range(1,nums[cur]+1):
            if i+cur>=n:
                break
            if(dfs(i+cur)):
                return True
        return False
    return dfs(0)    

def canJumpDP(nums):  #bottom-up of dp
    n=len(nums)
    dp=[False]*n
    dp[-1]=True
    for i in range(n-2,-1,-1):
        reach=min(i+nums[i],n-1)
        for j in range(i+1,reach+1):
            if dp[j]:
                dp[i]=True
    return dp[0]
        
def canJumpGreedy(nums):  #Greedy method,
    i,n=0,len(nums)
    reach=0
    while i<n and i<=reach:
        reach =max(i+nums[i],reach)
        i+=1   # can not support ++i
    return reach>=n-1
nums=[2,3,1,0,4]
print(canJumpGreedy(nums))
# i=1
# i+=1
# print(i)
