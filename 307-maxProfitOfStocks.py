import math
def maxProfit(prices):
    ans=0
    minV=math.inf
    
    for i in prices:
        minV=min(i,minV)
        ans=max(ans,i-minV)
    return ans

def maxProfitKadane(prices):
    n=len(nums)
    ans=cur=0
    for i in range(1,n):
        cur=max(prices[i]-prices[i-1]+cur,0)
        ans=max(ans,cur)
    return ans


nums=[1,2,3,4,55];
print(maxProfit(nums))
print(maxProfitKadane(nums))