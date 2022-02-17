from itertools import groupby

def packNums(nums):
    return [y for x,y in groupby(nums)]


(res)=packNums([1,1,1,2,2,3,4,4])
print(res)
print("----\n")
print()