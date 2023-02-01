# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        # INF=pow(2,31)
        st=[(root,-inf,inf)]
        while st:
            root,L,R =st.pop()
            if root.val<=L or root.val>=R:
                return False
            if root.left:
                st.append((root.left,L,root.val))
            if root.right:
                st.append((root.right,root.val,R))
        
        return True
    
        def isValidBST2(self, root: Optional[TreeNode]) -> bool:   
            prev = -inf
            def dfs(root):
                nonlocal prev
                if not root:
                    return True
                if not dfs(root.left):
                    return False
                if root.val <= prev:
                    return False
                prev = root.val
                return dfs(root.right)        
            return dfs(root) 