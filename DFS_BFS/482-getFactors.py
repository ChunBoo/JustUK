

"""
Numbers can be regarded as the product of their factors. For example, 8 = 2 x 2 x 2 = 2 x 4. Given an integer n, return all possible combinations of its factors. You may return the answer in any order.

Note that the factors should be in the range [2, n – 1].

Example 1:
Input: n = 1
Output: []

Example 2:
Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]

Example 3:
Input: n = 37
Output: []

Constraints:
1 <= n <= 10^7
"""

def getFactors(n):
    ans=[]
    def dfs(n,s,c):
        for i in range(s,int(n**0.5)+1):
            if n%i==0:
                c.append(i) #c+=[i]
                ans.append(c[:]+[n//i])
                dfs(n//i,i,c)
                c.pop()
    dfs(n,2,[])
    return ans

print(getFactors(12))