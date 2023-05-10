class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n=len(nums)
        ans=[0]*(n)
        k=1
        for i in range(0,n):
            ans[i]=k
            k*=nums[i]

        k=1
        for i in range(n-1,-1,-1):
            ans[i]*=k
            k*=nums[i]
        
        return ans