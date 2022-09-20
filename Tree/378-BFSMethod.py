from collections import defaultdict
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
    
    