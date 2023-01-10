# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
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

def averageOfSubtree( root):
    """
    :type root: Optional[TreeNode]
    :rtype: int
    """
    ans=0
    def dfs(root,ans):
        # global ans
        if not root:
            return 0,0
        ls,ln=dfs(root.left,ans)
        rs,rn=dfs(root.right,ans)
        # global ans
        if (root.val==(ls+rs+root.val)/(ln+rn+1)):
            ans+=1
        return (ls+rs+root.val),(ln+rn+1)
    dfs(root,ans)
    return ans


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root):
        ans = 0
        
        def dfs(root):
            if not root:
                return 0, 0
            ls, ln = dfs(root.left)
            rs, rn = dfs(root.right)
            s = ls + rs + root.val
            n = ln + rn + 1
            if root.val == s // n:
                nonlocal ans
                ans += 1
            return s, n
        
        dfs(root)
        return ans
    
    
root= TreeNode(4);
eight= TreeNode(8);
five= TreeNode(5);
zero= TreeNode(0);
one= TreeNode(1);
six= TreeNode(6);

root.left=eight;
root.right=five;
eight.left=zero;
eight.right=one;
five.right=six;

print(Solution().averageOfSubtree(root))