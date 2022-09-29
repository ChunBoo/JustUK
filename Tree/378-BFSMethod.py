from collections import defaultdict,deque
class Tree:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def solve(self, root):
        G=defaultdict(list)
        
        def dfs(root,par):
            if not root:
                return 
            dfs(root.left,root)
            dfs(root.right,root)
            
            if par:
                G[root].append(par)
                G[par].append(root)
                
        def bfs(root):
            if not root or root.val&1:
                return 0
            
            ans=0
            q=deque([(root,1)])
            seen=set()
            seen.add(root)
            
            while q:
                cur,d=q.popleft()
                ans=max(ans,d)
                for c in G[cur]:
                    if c.val&1 ==0 and c not in seen:
                        seen.add(c)
                        q.append((c,d+1))
                        
            return ans
        
        dfs(root,None)
        ans=0
        for i in G:
            if i.val&1==0:
                ans=max(ans,bfs(i))
        return ans
    
root=Tree(0)
left1=Tree(8)
right1=Tree(2)

rLeft2=Tree(6)
rright2=Tree(0)
rLeft3=Tree(4)

root.left=left1
root.right=right1

right1.left=rLeft2
right1.right=rright2

rLeft2.left=rLeft3

s=Solution()
print(s.solve(root))