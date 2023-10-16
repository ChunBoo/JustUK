

def totalHammingDistance(nums):
    mask=1
    ans=0
    for i in range(32):
        cnt=0
        for v in nums:
            if mask&v:
                cnt+=1
        ans+=(len(nums)-cnt)*cnt
        mask<<=1
        
    return ans

nums=[4,14,2]
print(totalHammingDistance(nums))