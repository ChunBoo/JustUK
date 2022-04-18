def sumOfuniquenumbers(nums):
    return sum([i for i in nums if nums.count(i)==1])

print(sumOfuniquenumbers([1,2,2,1,1,3,4]))