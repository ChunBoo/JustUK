
def countPrimeSetBits(left,right):
    primers=[2,3,5,7,11,13,17,19]
    def countOfBits(val):
        ans=0
        while val>0:
            ans+=(val&1)
            val=val>>1
        return ans
    res=0
    while left<=right:
        cnt=countOfBits(left)
        # isPrimer=
        if cnt in primers:
            res+=1
        left+=1
    
    return res


print(countPrimeSetBits(6,10))