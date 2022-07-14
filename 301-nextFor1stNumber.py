#use the next() to get the first number which larger or equal to the target 

def nextExample(nums,T):
    return next((x for x in nums if x>=T),-1)  # should be add the parenthesis if there is a default value

nums=[20,30,10,5,7]

print(nextExample(nums,45))