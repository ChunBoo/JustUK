
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        k%=n

        nums=nums[::-1]
        
        left=nums[:k]
        right=nums[k:]

        left.reverse()
        right.reverse()
        return left+right
    def rotate2(self,nums,k):
        n=len(nums)
        k%=n
        def reverse(l,r,nums):
            while l<r:
                nums[l],nums[r]=nums[r],nums[l]
                l+=1
                r-=1
        reverse(0,n-1,nums)
        reverse(0,k-1,nums)
        reverse(k,n-1,nums)
        return nums
    
nums=[1,2,3,4,5,6,7]
print(Solution().rotate(nums,3))
print(Solution().rotate2(nums,3))