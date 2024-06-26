'''
Given an array arr[] where each element represents the max number of steps that can be made forward from that index. 
The task is to find the minimum number of jumps to reach the end of the array starting from index 0. 
If the end isn’t reachable, return -1.
'''

from functools import cache
class Solution:
    def jump(self, nums):# List[int]) -> int:
        n=len(nums)
        @cache
        def dp(i):
            if i>=n-1:
                return 0
            if i+nums[i]>=n-1:
                return 1
            ans=n  #can not define this ans as global varaible
            #1. Global Variable Misuse: The use of ans as a global variable inside the dp function is not appropriate. In Python, the global keyword is used to refer to variables defined at the top level of the script, 
            #not for variables defined outside of a nested function. Moreover, modifying ans inside the dp function affects its value across all recursive calls, which is not the intended logic for dynamic programming.
            for s in range(1,nums[i]+1):
                ans=min(ans,dp(s+i)+1)
            return ans
        return dp(0)

nums=[1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
print(Solution().jump(nums))