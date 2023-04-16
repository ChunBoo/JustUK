from random import choice
#o(nlogn)
def sortArray(nums):
    n=len(nums)
    if n<=1:
        return nums
    
    smaller=[]
    equal=[]
    greater=[]
    pivot=choice(nums)
    
    for i in nums:
        if i<pivot:
            smaller.append(i)
        elif i==pivot:
            equal.append(i)
        else:
            greater.append(i)
    return sortArray(smaller)+equal+sortArray(greater)

nums=[4,1,5,3,2]
print(sortArray(nums))
    