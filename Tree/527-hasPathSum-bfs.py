
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def hasPathSum(root,target):
    if not root:
        return false;
    q=deque([(root,0)])  #here can not be deque(((root,0)))
    while q:
        curNode,s=q.pop()
        curVal=curNode.val+s
        if curVal==target and not curNode.left and not curNode.right:
            return True
        if curNode.left:
            q.append((curNode.left,curVal)) 
        if curNode.right:
            q.append((curNode.right,curVal))
    return False


root=TreeNode(7)
left1=TreeNode(1)
left12=TreeNode(2)
right12=TreeNode(5)
root.left=left1
left1.left=left12
left1.right=right12

print(hasPathSum(root,11))
    