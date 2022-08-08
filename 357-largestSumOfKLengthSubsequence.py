


def largestSumOfKLengthSubSequence(nums,k):
    if k<1 or k>len(nums):
        return
    
    w=list(nums[:k])
    
    for i in range(k,len(nums)):
        minVal=min(w)  #greedy algorithm
        if nums[i]>minVal:
            w.remove(minVal)
            w.append(nums[i])
            
    return w


nums=[3,5,2,1,7,7]
print(largestSumOfKLengthSubSequence(nums,3))