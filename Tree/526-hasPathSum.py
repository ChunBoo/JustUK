# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:

        def f(root,s):
            if not root:
                return False
            
            s+=root.val
            if s==targetSum and not root.left and not root.right:
                return True
            return f(root.left,s) or f(root.right,s)

        return f(root,0)