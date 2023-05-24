class Solution:
    def jump(self, nums: List[int]) -> int:
        n=len(nums)
        @cache
        def dp(i):
            if i>=n-1:return 0
            if i+nums[i]>=n-1:
                return 1
            ans=n
            for s in range(1,nums[i]+1):
                    ans=min(ans,dp(i+s)+1)
            return ans
        
        return dp(0)