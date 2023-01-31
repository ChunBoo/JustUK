# Definition for a binary tree node.
'''
Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
A subtree of a node node is node plus every node that is a descendant of node.

Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

'''
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    # def printTree(self):
    #     while 
class Solution(object):
    def pruneTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        if not root:
            return
        
        root.left=self.pruneTree(root.left)
        root.right=self.pruneTree(root.right)
        
        if not root.left and not root.right and root.val!=1:
            return None
        return root
    

root=TreeNode(1)
left=TreeNode(0)
right=TreeNode(1)
right2=TreeNode(1)
root.left=left
root.right=right
right.right=right2

Solution().pruneTree(root)
