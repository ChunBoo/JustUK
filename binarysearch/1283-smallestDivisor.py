


def smallestDivisor(nums,threshold):
    
    def sum(d):
        sum=0
        for v in nums:
            sum+=(v+(d-1))//d
        return sum
    
    ans=0
    l=1
    r=max(nums)
    while l<r:
        m=l+(r-l)//2
        if sum(m)<=threshold:
            r=m
        else:
            l=m+1
    return l

nums = [1,2,5,9]
threshold = 6
print(smallestDivisor(nums,threshold))