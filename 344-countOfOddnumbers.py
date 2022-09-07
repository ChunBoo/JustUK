import math

def isOddBit(num):
    nSize=len(str(num))
    return nSize&1


def isOddBits(num):
    if num==0:
        return 1
    
    return int(math.log10((num))+1)&1   #log10(99)<log10(100)=2

def countOfOddNumbers(nums):
    ans=0
    for v in nums:
        if isOddBit(v):
            ans+=1
    return ans

def countOfOddNumbers2(nums):
    return [isOddBit(i) for i in nums].count(True)

nums=[123,4,23,0,1]
print(countOfOddNumbers2(nums))