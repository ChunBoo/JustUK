

def singleNonDuplite(nums):
    _n=len(nums)
    l,r=0,_n
    
    while l<r:
        m=l+(r-l)//2
        n= m+1 if (m&1)==0 else m-1
        if nums[m]==nums[n]:
            l=m+1
        else:
            r=m
            
    return nums[l]

nums = [3,3,7,7,10,11,11]
print(singleNonDuplite(nums))