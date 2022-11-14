




def subsets(nums):
    ans=[[]]
    
    for i in nums:
        ans+=[c+[i] for c in ans]
    
    return  ans


nums=[1,2,3]
ans=subsets(nums)
print(ans)