"""
given a list of integers nums. Return the maximum possible abs(nums[i] + nums[i + 1] + … + nums[j]) for any i <= j.

Constraints
0 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [5, -7, -2, 4]
Output
9
Explanation
We can take the sublist [-7, -2] to get abs(-7 + -2) = 9.
"""


#sublist/subarray is continuous, but subsequence is not 
# [1,2,3], [1,3] is subsequence


def longestSubListSum(nums):
    if not nums:
        return 0
    
    ans=abs(nums[0])
    low=nums[0]
    high=nums[0]
    
    for i in nums[1:]:
        low=min(low+i,i)
        high=max(high+i,i)
        ans=max(ans,-low,abs(high))
        
    return ans

nums=[1,2,3,-4,-5]
print(longestSubListSum(nums))