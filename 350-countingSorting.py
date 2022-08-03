

from collections import Counter


def countingSort(nums):
    if not nums:
        return
    
    cnt=Counter(nums)
    data=[]
    minV=min(nums)
    maxV=max(nums)
    for i in range(minV,maxV+1):
        data.append([i]*cnt[i])
    return data

nums=[1,3,2,5,2,10]
print(countingSort(nums))