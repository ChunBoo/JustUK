class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        def gcd(a,b):
            while b:
                a,b=b,a%b
            return a
            if b:
                return gcd(b,a%b)
            return a
        ans=1
        x=gcd(a,b)
        for i in range (2,x+1):
            if x%i==0:
                ans+=1
        return ans