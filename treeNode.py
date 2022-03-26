# from tkinter.messagebox import NO


class TreeNode:
    def __init__(self,val) -> None:
        self.m_val=val
        self.left=None
        self.right=None
    def addLeftChild(self,left):
        self.left=left
    
    def addRightChild(self,right):
        self.right=right
        
    