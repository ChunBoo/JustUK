

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
    

def substreeWithAlldeepest(root):
    if not root:
        return None

    def depth(root):
        if not root:
            return [-1,None]
        
        dl,_left=depth(root.left)
        dr,_right=depth(root.right)

        return [max(dl,dr)+1,root if dl==dr else _left if dl>dr else _right]
    
    return depth(root)[-1]


one = TreeNode(1)
two = TreeNode(2)

root = TreeNode(3)
four = TreeNode(4)

five = TreeNode(5)
six = TreeNode(6)
seven = TreeNode(7)
eight = TreeNode(8)
nine = TreeNode(9)

root.left = five
root.right = six

five.left = one
five.right = two

two.left = seven
two.right = four

six.left = eight
six.right = nine

print(substreeWithAlldeepest(root).val)