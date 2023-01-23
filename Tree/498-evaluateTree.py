# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def evaluateTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        def dfs(root):
            if not root.left and not root.right:
                return root.val==1
            
            l=dfs(root.left)
            r=dfs(root.right)
            if root.val ==3:
                return l and r
            return l or r
        
        return dfs(root)
    
    
"""
We need to evaluate the leaf nodes first and then use the value to recursively evaluate the rest. 
This can be done easily via Recursion. See below Recursive Depth First Search Algorithm where we call the recursive function to obtain the value for the left and right subtrees respectively, 
    and then based on the binary operator, we return the value for the current node.

If it is a leaf node, 
we can just return the value of itself.
The time/space complexity is O(N) where N is the number of the nodes in the given boolean binary tree. Each node in the binary tree is visited once in the Recursion, and in the worst case, 
the calling stack step is N when the binary tree has only one child in each node.
"""