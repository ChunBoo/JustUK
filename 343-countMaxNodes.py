"""_summary_
Given a binary tree root, count and return the number of nodes where its value is greater than or
equal to the values of all of its descendants.

Constraints
n ≤ 100,000 where n is the number of nodes in root
Example 1
image.png
Input
binary-tree-max-value Teaching Kids Programming - Counting Maximal Value Roots in Binary Tree (Recursive Post-Order Traversal - DFS Algorithm) algorithms DFS python recursive teaching kids programming youtube video 
Output
4
Explanation
Since all nodes except for 2 meet the criteria.

Hint:
what if at every moment we have maximum from left and right sub-tree and then transfer maximum of {root,left,right} upwards? recursion?
Returns:
    _type_: _description_
"""

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