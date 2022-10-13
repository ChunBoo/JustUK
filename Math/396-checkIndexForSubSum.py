
def checkIndex(nums):
    t=sum(nums)
    right,left=t,0
    for i,v in enumerate(nums):
        right-=v
        if(right==left):
            return i
        left+=v
    return -1


nums=[2,2,5,0,2,3,4]
print(checkIndex(nums))