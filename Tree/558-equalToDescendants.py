"""

the root of a binary tree, return the number of nodes where the value
of the node is equal to the sum of the values of its descendants. 
A descendant of a node x is any node that is on the path from node x
to some leaf node. 
The sum is considered to be 0 if the node has no descendants.
"""
class TreeNode:
    def __init__(self,v):
        self.val=v
        self.left=None
        self.right=None

def equalToDescendants(root):
    ans=0
    def dfs(root):
        if not root:
            return 0
        ls=dfs(root.left)
        rs=dfs(root.right)
        if ls+rs==root.val:
            nonlocal ans
            ans+=1
        return ls+rs+root.val
    dfs(root)
    return ans


root=TreeNode(10)
four=TreeNode(4)
three=TreeNode(3)
two=TreeNode(2)
one=TreeNode(1)
root.left=three
root.right=four
three.left=two
three.right=one

print(equalToDescendants(root))