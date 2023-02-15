from itertools import groupby

class Solution:
    def countAndSay(self, n: int) -> str:
        def f(n):
            if n==1:
                return "1"
            a=f(n-1)
            ans=[]            
            for i,j in groupby(a):
                ans.append(str(len(list(j)))+i)
            return "".join(ans)
        return f(n)
    
    
print(Solution().countAndSay(5))