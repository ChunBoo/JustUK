
import math


def minABSDiffOfTwoNumbers(nums):
    nums.sort()
    minDiff=math.inf
    for i in range(1,len(nums)):
        minDiff=min(nums[i]-nums[i-1],minDiff)
    ans=[]
    for i in range(1,len(nums)):
        curDiff=nums[i]-nums[i-1]
        if curDiff==minDiff:
            ans+=[[nums[i-1],nums[i]]]
    return ans

def minAbsDiffOfTwoNumbers(nums):
    sz=len(nums)
    ans=[]
    minAbs=math.inf
    for i in range(sz):
        for j in range(sz):
            if i==j:
                continue
            if abs(nums[j]-nums[i])<minAbs:
                minAbs=abs(nums[j]-nums[i])
                
    for i in range(sz-1):
        for j in range(i,sz):
            if i==j:
                continue
            curDiff=abs(nums[i]-nums[j])
            if curDiff==minAbs:
                ans+=[[nums[i],nums[j]]]
                
    return ans



nums=[3,4,100,30,20,19,21]
print(minABSDiffOfTwoNumbers(nums))