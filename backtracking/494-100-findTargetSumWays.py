"""
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
"""
from functools import lru_cache
class Solution:
    def findTargetSumWays(self, nums,target):

        target+=sum(nums)
        if target<0 or target&1:
            return 0
        target//=2
        n=len(nums)
        @lru_cache
        def dfs(i,c):
            if i<0:
                return 1 if c==0 else 0
            if c<nums[i]:
                return dfs(i-1,c)
            return dfs(i-1,c)+dfs(i-1,c-nums[i])
        
        return dfs(n-1,target)