# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
"""
Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation:
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
    Returns:
        _type_: _description_
"""
class Solution(object):
    ans=0
    def averageOfSubtree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        # ans=0
        global ans
        def dfs(root):
            global ans
            if not root:
                return 0,0
            ls,ln=dfs(root.left)
            rs,rn=dfs(root.right)
            # global ans
            if (root.val==(ls+rs+root.val)/(ln+rn+1)):
                self.ans+=1
            return (ls+rs+root.val),(ln+rn+1)
        dfs(root)
        return self.ans