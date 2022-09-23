
#LC 334
from cmath import inf


def isIncreasingTriples(nums):
    
    a,b=inf,inf
    for i in nums:
        if i<=a:
            a=i
        elif i<=b:
            b=i
        else:
            return True
    return False


nums=[1,0,-1,2,0,4,5]
print(isIncreasingTriples(nums))