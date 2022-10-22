import math
class Solution(object):
    def simplifiedFractions(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        fracs=[]
        for i in range(2,n+1):
            for j in range(1,i):
                if math.gcd(j,i)==1 or j==1:
                    tmp=str(j)+"/"+str(i)
                    fracs.append(tmp)
                
        return fracs
    
s=Solution()
print(s.simplifiedFractions(6))