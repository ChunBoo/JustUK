class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        n=len(nums)
        ans=[0 for i in range(n)]

        i,j=0,n-1
        idx=n-1
        while i<=j:
            ci=nums[i]**2
            cj=nums[j]**2
            if(ci<cj):
                j-=1
                ans[idx]=cj
            else:
                i+=1
                ans[idx]=ci
            idx-=1
        return ans