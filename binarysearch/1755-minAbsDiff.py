
#
# from collections import set
from bisect import bisect_left
def minAbsDifference(nums,t):
    n=len(nums)
    t1,t2=[0],[0]
    
    ans=abs(t)
    
    for i in range(n//2):
        for j in range(len(t1)-1,-1,-1):
            t1.append(t1[j]+nums[i])
            
    for i in range(n//2,n):
        for j in range(len(t2)-1,-1,-1):
            t2.append(t2[j]+nums[i])
            
    t2.sort();  #set in python is unordered
    s1=set(t1)
    for v in s1:
        pos=bisect_left(t2,t-v)
        if pos<len(t2):
            ans=min(ans,abs(t-v-t2[pos]))
        if pos>0:
            ans=min(ans,abs(t-v-t2[pos-1]))
    return ans
    
nums = [7,-9,15,-2]
goal = -5
print(minAbsDifference(nums,goal))