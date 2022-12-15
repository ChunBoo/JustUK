from collections import defaultdict
def partitionByK(nums,k):
    n=len(nums)
    if n&1:
        return False
    s=defaultdict(int)
    
    for i in nums:
        s[i%k]+=1
    if s[0]&1:
        return False
    
    for i in range(1,k):
        if s[i]!=s[k-i]:
            return  False
    return True

nums=[1,2,4,8]
print(partitionByK(nums,3))