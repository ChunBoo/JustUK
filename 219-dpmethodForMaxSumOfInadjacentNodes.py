
# def _max(a,b,c,d):
#     return max(a,b,c,d)


# print(_max(1,2,3,4))

from treeNode import TreeNode

def dp(root):
    if root is None:
        return (0,0)
    takeleft,notTakeLeft=dp(root.left)
    takeright,notTakeRight=dp(root.right)
    takeRoot=root.val+notTakeLeft+notTakeRight
    notTakeRoot=max(takeleft,notTakeLeft)+max(takeright,notTakeRight)
    return takeRoot,notTakeRoot  #can not return max(takeRoot,notTakeRoot),TypeError: cannot unpack non-iterable int object


root=TreeNode(1)
left=TreeNode(2)
right=TreeNode(3)
leftLeft=TreeNode(5)
leftRight=TreeNode(6)
left.left=(leftLeft)
left.right=(leftRight)
root.left=(left)
root.right=(right)

res=max(dp(root))
print(res)