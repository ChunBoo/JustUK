


from operator import truediv


def checkDuplicate(nums,k):
    data=set()
    for i,v in enumerate(nums):
        if i>k:
            data.remove(nums[i-k-1]);
        if v in data:
            return True
        data.add(v)
        
    return False

nums=[2,1,3,2,4,6]
print(checkDuplicate(nums,2))