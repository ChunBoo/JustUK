
# Definition for a binary tree node.
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
def preOrderStack(root):
    if not root:
        return []
    
    s=[]
    s.append(root)
    while s:
        


def bfoo(root):
    if not root:
        return []
    ans=[]
    q=deque([root])
    while q:
        cur=q.popleft()
        ans.append(cur.val)
        if cur.left:
            q.append(cur.left)
        if cur.right:
            q.append(cur.right)
            
    return ans

root=TreeNode(1)
two=TreeNode(2)
three=TreeNode(3)
root.left=two
root.right=three

print(bfoo(root))