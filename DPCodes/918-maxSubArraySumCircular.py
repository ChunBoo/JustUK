'''
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n]
and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. 
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
'''


class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n=len(nums)
        @cache
        def dp(i,s):
            if i==0:
                return nums[i]*s
            return nums[i]*s+max(0,dp(i-1,s))
        
        max_p=max(dp(i,1) for i in range(n))
        max_n=max(dp(i,-1) for i in range(n))

        return max_p if max_p<0 else max(max_p,sum(nums)+max_n)