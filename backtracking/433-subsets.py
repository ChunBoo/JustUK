class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n=len(nums)
        ans=[]
        def dfs(cur,i):
            if i==n:
                ans.append(cur)
                return
            
            dfs(cur,i+1)
            dfs(cur+[nums[i]],i+1)
            
        dfs([],0)
        return ans


s=Solution()
print(s.subsets([1,2,3]))