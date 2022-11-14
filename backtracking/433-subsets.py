
'''
As the Python uses Object-References when passing parameters,
the list (mutable) is passed by References, 
we need to make a deep copy (using copy.deepcopy(cur) or cur[:]) to copy the current subset e.g. cur to answer (list of all subsets).
'''

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
                ans.append(cur[:])
                return
            
            dfs(cur,i+1)
            dfs(cur+[nums[i]],i+1)
            
        dfs([],0)
        return ans
    def subsets2(self, nums):
        n = len(nums)
        ans = []        
        for i in range(1 << n):
            cur = []
            for j in range(n):
                if i & (1 << j):
                    cur.append(nums[j])
            ans.append(cur)
        return ans   


s=Solution()
print(s.subsets2([1,2,3]))