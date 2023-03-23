class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans=[]
        candidates.sort()
        n=len(candidates)

        def dfs(sum,idx,cur):
            if sum>target or idx==n:
                return 
            if sum==target:
                ans.append(cur)
                return
            
            for j in range(idx,n):
                if sum+candidates[j]>target:
                    break
                dfs(sum+candidates[j],j,cur+[candidates[j]])
        dfs(0,0,[])
        return ans
                
candidates = [2,3,6,7]
target = 7