from treeNode import TreeNode
import math

ans=-math.inf

def sum(root):
    if not root:
        return 0
    
    return root.val+sum(root.left)+sum(root.right)


def dfs(root,T):
    if not root:
        return 0
    cur=root.val+dfs(root.left,T)+dfs(root.right,T)
    global ans
    ans=max(ans,T*(T-cur))
    
    return cur

def maxProduct(root):
    T=sum(root)
    dfs(root,T)
    return ans


root=TreeNode(1)
L1=TreeNode(2)
R1=TreeNode(3)
LL2=TreeNode(4)
LR2=TreeNode(5)

RL2=TreeNode(6)

root.left=L1
root.right=R1

L1.left=LL2
L1.right=LR2

R1.left=RL2

print(maxProduct(root))