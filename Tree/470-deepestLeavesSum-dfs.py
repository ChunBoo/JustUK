# Definition for a binary tree node.
# Given the root of a binary tree, return the sum of values of its deepest leaves.
#Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]

from collections import defaultdict

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
        
        d=defaultdict(int)
        def dfs(root,lvl):
            if not root:
                return
            d[lvl]+=root.val
            dfs(root.left,lvl+1)
            dfs(root.right,lvl+1)
            
        dfs(root,0)
        return d[max(d.keys())]
