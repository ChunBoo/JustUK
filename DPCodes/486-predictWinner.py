

def predictWinner(nums):
    n=len(nums)
    m=[0]*(n*n)

    def getScore(l,r):
        if l==r:
            return nums[l]
        
        if m[l*n+r]:
            return m[l*n+r]
        
        m[l*n+r]=max(nums[l]-getScore(l+1,r),nums[r]-getScore(l,r-1))
        return m[l*n+r]
    return getScore(0,n-1)>=0
    
nums=[1,5,2]
print(predictWinner(nums))


