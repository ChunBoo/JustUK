
def moveZeros(nums):
    n=len(nums)
    cnt=0
    for i in range(n):
        if nums[i]!=0:
            nums[cnt]=nums[i]
            cnt+=1
    while cnt<n:
        nums[cnt]=0
        cnt+=1
    
nums = [0,1,0,3,12]
moveZeros(nums)
print(nums)