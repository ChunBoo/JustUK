""" 1447
Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can return the answer in any order.

 

Example 1:

Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.
Example 2:

Input: n = 3
Output: ["1/2","1/3","2/3"]
Example 3:

Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".


"""

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