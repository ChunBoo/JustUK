
def nextExample(nums,T):
    return next((x for x in nums if x>=T),-1)

nums=[20,30,10,5,7]

print(nextExample(nums,25))