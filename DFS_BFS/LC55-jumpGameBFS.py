from collections import deque
class Solution:
    def canJump(self, nums):
        
        n=len(nums)
        seen=set()
        q=deque([0])
        while q:
            cur=q.popleft()
            for i in range(0,nums[cur]+1):
                next=cur+i
                if next not in seen and next<n:
                    if next+nums[next]>=n-1:
                        return True;
                    q.append(next)
                    seen.add(next)
        return False
    
num=[3,2,1,0,4]
s=Solution()
print(s.canJump(num))