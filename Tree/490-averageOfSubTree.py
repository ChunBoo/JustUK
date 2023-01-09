# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
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