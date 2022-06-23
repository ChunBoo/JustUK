

def mymax(nums):
    n=len(nums)
    if n==1:
        return nums[0]
    
    mid=n//2
    
    leftmax=mymax(nums[:mid])
    rightmax=mymax(nums[mid:])
    
    if leftmax<rightmax:
        return rightmax
    
    return leftmax



nums=[2,16,1,3,4,9,0]
print(mymax(nums))