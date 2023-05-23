'''
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

'''

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        # houses=[0]*(10**4+1)
        houses=defaultdict(int)
        for x in nums:
            houses[x]+=x
        
        @cache
        def dp(i):
            if i<0:
                return 0
            
            return max(dp(i-2)+houses[i],dp(i-1))
        return dp(len(nums)-1)