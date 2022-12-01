from collections import defaultdict
def intersection( nums):
    """
    :type nums: List[List[int]]
    :rtype: List[int]
    """
    n=len(nums)
    d=defaultdict(int)
    ans=[]
    for v in nums:
        for i in v:
            d[i]+=1
    for k,v in d.items():
        if v==n:
            ans.append(k)
    return sorted(ans)


def intersectionSet(nums):
    if not nums:
        return []
    a=set(nums[0])

    for i in nums[1:]:
        a=a.intersection(set(i))
    return sorted(a)

nums=[[7,34,45,10,12,27,13],[27,21,45,10,12,13]]
print(intersectionSet(nums))