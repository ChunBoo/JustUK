# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def getAllElements(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: List[int]
        """
        def inorder(root):
            if not root:
                return 
            return inorder(root.left)+[root.val]+inorder(root.right)
        
        a=inorder(root1)
        b=inorder(root2)
        la,lb=len(a),len(b)
        i,j=0,0
        ans=[]
        while i<la and j<lb:
            if a[i]<=b[j]:
                ans.append(a[i])
                i+=1
            else:
                ans.append(b[j])
                j+=1
        if i<la:
            ans.extend(a[i:])
        if j<lb:
            ans.extend(b[j:])
        return ans
        