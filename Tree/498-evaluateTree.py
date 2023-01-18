# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def evaluateTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        def dfs(root):
            if not root.left and not root.right:
                return root.val==1
            
            l=dfs(root.left)
            r=dfs(root.right)
            if root.val ==3:
                return l and r
            return l or r
        
        return dfs(root)