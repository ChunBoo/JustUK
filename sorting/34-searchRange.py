class Solution:
    def searchRange(self, nums, target):
        
        n=len(nums)
        s,e=-1,-1
        if n==0:
            return [s,e]
        if target<nums[0] or target>nums[n-1]:
            return [s,e]
        if target==nums[0] and n==1:
            return [0,0]
        l,r=0,n-1
        while l<=r:
            mid=(l+r)//2
            if target==nums[mid]:
                s=mid
                e=mid
                while(s>0 and nums[s]==nums[s-1]): s-=1
                while(e<n-1 and nums[e]==nums[e+1]): e+=1
                return [s,e]
            elif target>nums[mid]:l+=1
            else: r-=1;
        return [s,e]
    

nums=[0,1,2,3,3,5,6,3]
print(Solution().searchRange(nums, 3))