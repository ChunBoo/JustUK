from math import log2
class Solution:
    def concatenatedBinary1(self, n: int) -> int:
        arr=[bin(i)[2:] for i in range(1,n+1)]
        return int("".join(arr),2)%(pow(10,9)+7)
    def concatenatedBinary2(self, n: int) -> int:
        ans=0
        b=0
        M=10**9+7
        for i in range(1,n+1):
            if i&(i-1)==0:    
                b+=1
            ans<<=b
            ans+=i
            ans%=M

        
        return ans
    
    def isPowerofTwo1(self,n):
        x=int(log2(n))
        return 2**x==n
    
    def isPowerOfTwo2(self,n):
        return log2(n).is_integer()