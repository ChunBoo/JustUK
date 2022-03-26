class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
    def addLeftChild(self,left):
        self.left=left
    def addRightChild(self,right):
        self.right=right
