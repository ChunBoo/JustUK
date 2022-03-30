
# def _max(a,b,c,d):
#     return max(a,b,c,d)


# print(_max(1,2,3,4))

from treeNode import TreeNode

def dp(root):
    if root is None:
        return 0,0
    takeLeft,notTakeLeft=dp(root.left)
    takeRight,notTakeRight=dp(root.right)
    
    takeRoot=root.val+notTakeLeft+notTakeRight
    notTakeRoot=max(takeLeft,notTakeLeft)+max(takeRight,notTakeRight)
    
    return takeRoot,notTakeRoot

root=TreeNode(1);
left=TreeNode(2)
right=TreeNode(3)
leftLeft=TreeNode(5)
leftRight=TreeNode(6)
left.addLeftChild(leftLeft)
left.addRightChild(leftRight)
root.addLeftChild(left)
root.addRightChild(right)

res=max(dp(root))
print(res)