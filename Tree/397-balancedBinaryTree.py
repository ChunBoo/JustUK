#LC110
ans=True
def depth(root):
    if not root:
        return 0
    
    left=depth(root.left)
    right=depth(root.right)
    if abs(left-right)>1:
        ans=False
        return ans
    return max(left,right)+1


def isBalanced(root):
    if not root:
        return True
    return isBalanced(root.left)&isBalanced(root.right) and abs(depth(root.left)-depth(root.right))<=1