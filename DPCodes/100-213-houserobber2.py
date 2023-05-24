'''
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, 
    and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

'''
from functools import cache
class Solution:
    def rob(self, nums):# List[int]) -> int:
        n=len(nums)
        if n==1:   #this special case can not be skipped
            return nums[0]
        @cache
        def dp(i,j):
            if j<i:
                return 0
            return max(nums[j]+dp(i,j-2),dp(i,j-1))
        return max(dp(0,n-2),dp(1,n-1))
    
nums = [2,3,2]
print(Solution().rob(nums))