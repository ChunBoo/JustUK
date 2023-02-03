# Definition for a binary tree node.
from math import inf
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root):
        if not root:
            return True
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
    
    def isValidBST2(self, root):
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

six=TreeNode(9)
seven=TreeNode(7)
four=TreeNode(4)
five=TreeNode(5)
three=TreeNode(3)
two=TreeNode(2)
one=TreeNode(1)
eight=TreeNode(8)

two.left=one
two.right=three
five.left=four
five.right=six
four.left=two
seven.left=five

seven.right=eight

print(Solution().isValidBST2(seven))