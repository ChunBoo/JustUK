
from treeNode import TreeNode

seen=[]
def dfs(root):
    if not root:
        return 0
    s=root.val+dfs(root.left)+dfs(root.right)
    seen.append(s)
    return s

root=TreeNode(10)
left=TreeNode(5)
right=TreeNode(10)
l21=TreeNode(2)
r22=TreeNode(3)
root.left=left
right.left=l21
right.right=r22
root.right=right

print(dfs(root)/2 in seen)