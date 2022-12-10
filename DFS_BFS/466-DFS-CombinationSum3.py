"""
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, 
and the combinations may be returned in any order.
"""
from itertools import combinations,permutations

def simpleMethod(k,n):
    return [x for x in list(combinations(range(1,10),k)) if sum(x)==n]
def combinationSum3(k, n):
    """
    :type k: int
    :type n: int
    :rtype: List[List[int]]
    """
    ans=[]
    if k>9 or n>45:
        return []
    
    def dfs(cur,a):
        if len(cur)>k or sum(cur)>n:
            return 
        if len(cur)==k and sum(cur)==n:
            ans.append(cur[:])
        for i in range(a,10):
            dfs(cur+[i],i+1)
    dfs([],1)
    return ans

print(combinationSum3(3,9))
print(simpleMethod(3,9))