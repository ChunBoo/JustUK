def minKDiff(nums,k):
    nums.sort()
    return min(nums[i+k-1]-nums[i] for i in range(len(nums)-k+1))

def minKDiff2(nums,k):
    nums.sort()
    return min(nums[i]-nums[i-k+1] for i in range(k-1,len(nums)))

nums=[1,2,3,10,20]
print(minKDiff2(nums,4))