from treeNode import TreeNode
import math
def countMaxNodes(root):
    ans=0
    
    def dfs(root):
        if not root:
            return -math.inf
        
        maxLeft=dfs(root.left)
        maxRight=dfs(root.right)
        nonlocal ans
        if(root.val>=max(maxLeft,maxRight)):
            ans+=1
        return max(maxLeft,maxRight,root.val)
    dfs(root)
    return ans

root=TreeNode(6)
left1=TreeNode(3)
right1=TreeNode(2)
left21=TreeNode(6)
right22=TreeNode(4)

root.left=left1
root.right=right1

right1.left=left21
right1.right=right22


print(countMaxNodes(root))