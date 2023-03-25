class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans=0
        n=len(nums)
        if n==0:
            return ans
        s=set(nums)
        step=1
        for v in s:
            if v-1 in s:
                continue
            while v+1 in s:
                step+=1
                v+=1
            ans=max(ans,step)
            step=1
        
        return ans
        
