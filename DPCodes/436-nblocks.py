'''
given two integers n and k. There are n blocks with heights ranging from 1 to n. 
Return the number of ways in which these n blocks can be arranged, 
in such a way that if you look from the left, exactly k blocks are visible.

For example, if n = 5, one way to arrange the blocks is:
                                *
                        *       *
                *       *       *
        *       *       *       * 
*       *       *       *       *
---------------------------------

'''

from functools import lru_cache
from math import factorial
@lru_cache
def f(n,k):
    if n<k:
        return 0
    if k==1:
        return factorial(n-1)
    
    if n==k:
        return 1
    
    return f(n-1,k-1)+(n-1)*f(n-1,k)


print(f(4,2))