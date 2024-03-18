"""
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

 

Example 1:

Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.
Example 2:

Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
Example 3:

Input: nums = [-1,-2,-3,0,1]
Output: 2
Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
"""

class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        # ans=0
        n=len(nums)
        @cache
        def dp(i:int)->tuple[int,int]:
            if i<0 or nums[i]==0:
                return 0,0
            p,n=dp(i-1)
            if nums[i]>0:
                return p+1,n+1 if n else 0
            else:
                return n+1 if n else 0, p+1

        return max(dp(i)[0] for i in range(n)) 
            
