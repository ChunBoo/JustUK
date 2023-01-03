from collections import defaultdict,deque
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def closetLeaf(root,k):
    leaves=set()
    G=defaultdict(list)
    def dfs(root,par):
        if not root:
            return 
        dfs(root.left,root)
        dfs(root.right,root)
        
        if par:
            G[root.val].append(par.val)
            G[par.val].append(root.val)
        if not root.left and not root.right:
            leaves.add(root.val)
    dfs(root,None)
    q=deque([k])
    seen=set()
    while q:
        cur=q.popleft()
        if cur in leaves:
            return cur
        for n in G[cur]:
            if n not in seen:
                seen.add(n)
                q.append(n)
                
root=TreeNode(0)
one=TreeNode(1)
two=TreeNode(2)
three=TreeNode(3)
four=TreeNode(4)
root.left=one
root.right=two
one.left=three
two.left=four

print(closetLeaf(root,2))
