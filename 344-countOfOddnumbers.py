import math

def isOddBit(num):
    nSize=len(str(num))
    return nSize%2!=0


def isOddBits(num):
    return int(math.log10((num))+1)&1

def countOfOddNumbers(nums):
    ans=0
    for v in nums:
        if isOddBit(v):
            ans+=1
    return ans


nums=[123,4,23,1]
print(countOfOddNumbers(nums))