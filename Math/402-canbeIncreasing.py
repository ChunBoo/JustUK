class Solution:
    def canBeIncreasing(self, nums):
        def is_strictly_increasing(arr):
            #return sorted(arr) == arr and len(arr) == len(set(arr))
            return all(arr[i] < arr[i + 1] for i in range(len(arr) - 1))

        for i in range(len(nums)):
            arr = nums[:i] + nums[i + 1:]
            if is_strictly_increasing(arr):
                return True
        
        return False
    
    def canIncreasing(self,nums):
        n=len(nums)
        dp=[1]*n
        for i in range(n):
            for j in range(i):
                if nums[j]<nums[i]:
                    dp[i]=max(dp[i],dp[j]+1)
        return max(dp)+1==n
    

s=Solution()
nums=[2,3,10,7,6]
print(s.canBeIncreasing(nums))
print(s.canIncreasing(nums))