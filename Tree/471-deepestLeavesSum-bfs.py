# Definition for a binary tree node.
# Given the root of a binary tree, return the sum of values of its deepest leaves.
#Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]

from collections import deque

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def deepestLeavesSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        q=deque([(root,0)])
        ans=0
        while q:
            n=len(q)
            for i in range(n):
                cur,lvl=q.popleft()
                ans+=cur.val
                if cur.left:
                    q.append((cur.left,lvl+1))
                if cur.right:
                    q.append((cur.right,lvl+1))
        return ans

