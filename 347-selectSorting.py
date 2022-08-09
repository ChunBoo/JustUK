
#sorted, unsorted


def selectSorting(nums):
    n=len(nums)
    
    for i in range(n):
        minIdx=i
        for j in range(i+1,n):
            if nums[j]<nums[minIdx]:
                minIdx=j
        nums[i],nums[minIdx]=nums[minIdx],nums[i]
      
    return nums



nums=[3,5,2,9,1,6];
newVals=selectSorting(nums)
print(newVals)