def findDisappearedNumbers(nums):
    n=len(nums)
    ans=[]    
    for i in range(n):
        nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1])
    for i in range(n):
        if nums[i]>0:
            ans.append(i+1)
    return ans


nums=[1,3,1]
print(findDisappearedNumbers(nums))