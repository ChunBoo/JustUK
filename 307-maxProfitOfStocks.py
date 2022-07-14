import math
def maxProfit(prices):
    ans=-math.inf
    minVal=math.inf
    for v in prices:
        minVal=min(minVal,v)
        ans=max(ans,v-minVal)
    return ans

def maxProfitKadane(prices):
    n=len(prices)
    ans=0
    maxVal=0
    for i in range(1,n):
        maxVal=max(prices[i]-prices[i-1]+maxVal,0)
        ans=max(ans,maxVal)
    return ans

nums=[1,0,3,6,9];
print(maxProfit(nums))
print(maxProfitKadane(nums))