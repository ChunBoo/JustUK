# Definition for a binary tree node.
from collections import deque


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return root
        ans=[]
        q=deque([root])
        while q:
            n=len(q)
            ans.append(q[-1].val)
            for _ in range(n):
                x=q.popleft()
                if x.left:
                    q.append(x.left)
                if x.right:
                    q.append(x.right)
                
        return ans
