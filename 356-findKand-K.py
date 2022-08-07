
"""
Given a list of integers nums, return the largest integer k where k and -k both exist in nums (they can be the same integer). If there's no such integer, return -1.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [-4, 1, 8, -5, 4, -8]
Output
8
"""

def findKAndNegativeK(nums):
    s=set(nums)
    
    ans=-1
    
    for i in nums:
        if -i in nums:
            ans=max(ans,i)

    return ans

nums = [-4, 1, 8, -5, 4, -8]
print(findKAndNegativeK(nums))