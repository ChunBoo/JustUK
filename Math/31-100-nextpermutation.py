def nextPermutation(nums):
    n=len(nums)
    i=0
    isFound=0
    for m in range(n-2,-1,-1):
        if nums[m]<nums[m+1]:
            i=m
            isFound=1
            break
    if not isFound:
        nums.reverse()
    else:
        for j in range(n-1,i,-1):
            if nums[j]>nums[i]:
                nums[i],nums[j]=nums[j],nums[i]
                tmp=nums[i+1:]
                tmp.reverse()
                for k in range(i+1,n):
                    nums[k]=tmp[k-i-1]
                break
    return nums
    
    
nums=[1,1,5]
print(nextPermutation(nums))
# print(nums)