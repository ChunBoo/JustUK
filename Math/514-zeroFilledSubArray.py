'''
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.

'''
from itertools import groupby
class Solution:
    def zeroFilledSubarray(self, nums):  #sub array is continue,but sub sequence is not necessary
        ans=0
        for a,b in groupby(nums):
            if a==0:
                n=len(list(b))
                ans+=(n*(n+1))//2
        return ans
        # z=0
        # for i in nums:
        #     if i==0:
        #         z+=1
        #         ans+=z
        #     else:
        #         z=0
        # return ans
        
nums = [1,3,0,0,2,0,0,4]
print(Solution().zeroFilledSubarray(nums))