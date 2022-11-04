# Definition for a binary tree node.
from collections import deque


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    def addLeft(self,node):
        self.left=node
    def addRight(self,node):
        self.right=node
        
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return root
        q=deque([root])
        ans=[]
        while q:
            ans.append(q[-1].val)
            n=len(q)
            for _ in range(n):
                x=q.popleft()
                if x.left:
                    q.append(x.left)
                if x.right:
                    q.append(x.right)
                
        return ans


nodes=[1,2,3,4,5]
root=TreeNode(1)
l1=TreeNode(2)
r1=TreeNode(3)
l2=TreeNode(4)
r2=TreeNode(5)
root.addLeft(l1)
root.addRight(r1)
l1.addLeft(l2)
l1.addRight(r2)
print(Solution().rightSideView(root))
    