class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        @cache
        def f(i,j):
            if i<0 or j<0:
                return 0
            if nums1[i]==nums2[j]:
                return f(i-1,j-1)+1
            return max(f(i-1,j),f(i,j-1))
        
        return f(len(nums1)-1,len(nums2)-1)
    
    
nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]