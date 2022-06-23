
#divided and conquer algorithm 
def mymax(nums):
    n=len(nums)
    if(n==1):
        return nums[0]  #this step is important to exit total codes,or it will be failed with maximum recursion depth exceeded
    mid=n//2
    
    leftmax=mymax(nums[:mid])
    rightmax=mymax(nums[mid:])
    
    if leftmax>rightmax:
        return leftmax
    return rightmax



nums=[2,16,1,3,4,9,0]
print(mymax(nums))