# Definition for a binary tree node.
from collections import deque
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        q=deque([(root,root)])
        while q:
            a,b=q.popleft()
            if not a and not b:
                continue
            if not a or not b:
                return False
            if a.val!=b.val:
                return False
            q.append((a.left,b.right))
            q.append((a.right,b.left))
        
        return True

        # def f(a,b):
        #     if not a and not b:
        #         return True
        #     if not a or not b:
        #         return False
        #     return a.val==b.val and f(a.left,b.right) and f(a.right,b.left)
        
        # return f(root,root)
        
root=TreeNode(10);
one=TreeNode(1)
two=TreeNode(2)
two2=TreeNode(2)
three=TreeNode(3)
four=TreeNode(4)

root.left=two
root.right=two2

two.left=three
two.right=four

two2.left=four
two2.right=three

print(Solution().isSymmetric(root))