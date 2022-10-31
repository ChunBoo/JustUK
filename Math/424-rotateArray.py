
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
    
nums=[1,2,3,4,5,6,7]
print(Solution().rotate(nums,3))