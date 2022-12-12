"""
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, 
and the combinations may be returned in any order.
"""
from itertools import combinations,permutations
from collections import deque
def simpleMethod(k,n):
    return [x for x in list(combinations(range(1,10),k)) if sum(x)==n]
def combinationSum3(k, n):
    """
    :type k: int
    :type n: int
    :rtype: List[List[int]]
    """
    # should determine the range of k and n is reasonable first
    if k>9 or n>45:
        return []
    ans=[]
    def f(cur,i,s):
        if len(cur)>k or s>n:
            return 
        if len(cur)==k and s==n:
            ans.append(cur[:])  #here should be deep copy 
        
        for x in range(i,10):
            f(cur+[x],x+1,s+x)  #here should be x+1 for next number
    f([],1,0)
    return ans 
            
        


print(combinationSum3(3,9))
print(simpleMethod(3,9))