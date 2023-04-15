'''
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        d=dict()

        def dfs(node):
            if not node:
                return 0
            if node in d:
                return d[node]
            t1,t2=0,0
            if node.left:
                t1+=dfs(node.left.left)+dfs(node.left.right)
            if node.right:
                t1+=dfs(node.right.left)+dfs(node.right.right)
            
            t1+=node.val
            t2=dfs(node.left)+dfs(node.right)
            d[node]=max(t1,t2)
            return d[node]
        return dfs(root)