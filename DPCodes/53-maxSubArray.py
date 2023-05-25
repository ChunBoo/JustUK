
'''
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

'''

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n=len(nums)
        @cache
        def dp(i):
            if i==0:
                return nums[i]
            return max(nums[i],nums[i]+dp(i-1))
        
        return max(dp(i) for i in range(n))
