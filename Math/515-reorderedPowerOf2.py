"""
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

 

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false
"""
from itertools import permutations
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        
        for a in permutations(str(n)):
            x="".join(a)
            y=int(x)
            if x[0]!='0' and y&(y-1)==0:
                return True

        return False
    
print(Solution().reorderedPowerOf2(254))