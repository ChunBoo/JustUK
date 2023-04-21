def maxProduct(nums):
    n=len(nums)
    fMax,fMin=nums[0],nums[0]
    for i in range(1,n):
        fMax=max(nums[i],fMax*nums[i],fMin*nums[i])
        fMin=min(nums[i], fMin*nums[i],fMax*nums[i])
    return fMax


nums=[-2,3,-4]
print(maxProduct(nums))