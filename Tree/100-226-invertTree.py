
class TreeNode:
    def __init__(self,val,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
    # @staticmethod
    def printPreOrder(self,root):        
        if not root:
            return None
        print(root.val)
        self.printPreOrder(root.left)
        
        self.printPreOrder(root.right)        

def invertTree(root):
    if not root:
        return None
    
    right=root.right
    root.right=invertTree(root.left)
    root.left=invertTree(right)
    return root


one=TreeNode(1)
two=TreeNode(2)
three=TreeNode(3)
four=TreeNode(4)
five=TreeNode(5)

one.left=two
one.right=three

two.left=four
three.right=five

one.printPreOrder(one)
res=invertTree(one)
print("------------")
res.printPreOrder(res)

