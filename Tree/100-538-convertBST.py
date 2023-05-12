class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
    def preOrder(self,root):
        if not root:
            return
        print(root.val)
        self.preOrder(root.left)
        self.preOrder(root.right)
class Solution:
    # num=0
    
    def convertBST(self, root):
        if not root:
            return None
        num=0
        def dfs(root):
            if not root:
                return None
            nonlocal num
            dfs(root.right)
            num+=root.val
            root.val=num
            dfs(root.left)
            
            return root
        return dfs(root)
    

one=TreeNode(1)
two=TreeNode(2)
three=TreeNode(3)
four=TreeNode(4)
five=TreeNode(5)

three.left=two
two.left=one

three.right=four
four.right=five

three.preOrder(three)
newRoot=Solution().convertBST(three)
print("----------------------")
newRoot.preOrder(newRoot)

