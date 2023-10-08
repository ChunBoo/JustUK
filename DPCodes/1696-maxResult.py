class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        @lru_cache(None)
        def dp(i:int)->int:
            if i==0: return nums[0]
            return nums[i]+max(dp(j) for j in range(max(0,i-k),i))
        return dp(len(nums)-1)