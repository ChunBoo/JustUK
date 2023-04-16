from collections import defaultdict,Counter

def median(nums):
    if not nums:
        return 0
    nums.sort()
    
    n=len(nums)
    if n&1:
        return (nums[n//2]+nums[n//2-1])//2
    else:
        return nums[n//2]
    
def mode(nums):
    if not nums:
        return 0
    count=Counter(nums)
    maxN=max(count.values())
    for i in nums:
        if count[i]==maxN:
            return i
        
nums=[5,3,1,4,2,3,3,2]
# print(median(nums))
print(mode(nums))