def sortColor(nums):
    n=len(nums)
    p0,p2=0,n-1
    for i in range(p2):
        while nums[i]==2 and i<=p2:
            nums[i],nums[p2]=nums[p2],nums[i]
            p2-=1
        if nums[i]==0:
            nums[i],nums[p0]=nums[p0],nums[i]
            p0+=1
            


nums=[2,2,0,1,0,1]
sortColor(nums)
print(nums)