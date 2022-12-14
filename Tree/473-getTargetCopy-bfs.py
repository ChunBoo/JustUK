# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution(object):
    def getTargetCopy(self, original, cloned, target):
        """
        :type original: TreeNode
        :type cloned: TreeNode
        :type target: TreeNode
        :rtype: TreeNode
        """
        q=deque([(original,cloned)])
        while q:
            n=len(q)
            for _ in range(n):
                a,b=q.popleft()
                if a is target:
                    return b
                if a.left:
                    q.append((a.left,b.left))
                if a.right:
                    q.append((a.right,b.right))