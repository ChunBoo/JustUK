# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getTargetCopy(self, original, cloned, target):
        """
        :type original: TreeNode
        :type cloned: TreeNode
        :type target: TreeNode
        :rtype: TreeNode
        """
        def dfs2(a,b,t):
            if not a:
                return
            if a is t:
                return b
            x=dfs2(a.left,b.left,t)
            if x:
                return x
            return dfs2(a.right,b.right,t)
        self.ans=None  #why self.ans is okay
        def  dfs(a,b,t):
            if not a:
                return 
            if a is t:
                self.ans=b
                return
            dfs(a.left,b.left,t)
            dfs(a.right,b.right,t)
        dfs(original,cloned,target)
        return self.ans
      