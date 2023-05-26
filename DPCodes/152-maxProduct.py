class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n=len(nums)
        @cache
        def dp(i:int)->Tuple[int,int]:
            if i==0:
                return nums[i],nums[i]
            
            low,hi=dp(i-1)
            if nums[i]<0:
                low,hi=hi,low
            return min(nums[i]*low,nums[i]),max(nums[i]*hi,nums[i])
        
        return max( dp(i)[1] for i in range(n))