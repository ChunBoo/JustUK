# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # num=0
    
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        num=0
        def dfs(root):
            if not root:
                return None
            
            dfs(root.right)
            nonlocal num
            num+=root.val
            root.val=num
            dfs(root.left)
            return root
        return dfs(root)