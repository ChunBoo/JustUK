
class Solution:
    def twoSumHashTable(self,nums,target):
        d=dict()
        for i,v in enumerate(nums):
            if target-v in d:
                return [d[target-v],i]
            d[v]=i
            
    def twoSum(self, nums, target):
        v1,v2=0,0
        bkNums=nums[::]
        nums.sort()
        n=len(nums)
        l,r=0,n-1
        while l<r:
            if nums[l]+nums[r]==target:
                v1=nums[l]
                v2=nums[r]
                break
            elif nums[l]+nums[r]<target:
                l+=1
            else:
                r-=1
        ans=[]
        for i in range(n):
            if bkNums[i] in (v1,v2):
                ans.append(i)
                if len(ans)==2:
                    return ans
nums=[-1,-2,-3,-4,-5]
# bkNums=nums[::]
# nums.sort()

print(Solution().twoSum(nums,-8))
nums=[-1,-2,-3,-4,-5]

print(Solution().twoSumHashTable(nums,-8))
