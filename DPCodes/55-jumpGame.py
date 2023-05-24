class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        @cache
        def dp(i):
            if i>=n-1:
                return True
            if i+nums[i]>=n-1:
                return True
            for s in range(1,nums[i]+1):
                if dp(s+i):
                    return True
            return False
        return dp(0)