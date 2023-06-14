# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

'''
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        if not root:
            return []
        ans=[]
        ds=set(to_delete)
        def process(root):
            if not root:
                return None
            root.left=process(root.left)
            root.right=process(root.right)
            if root.val not in ds:
                return root
            if root.left:
                ans.append(root.left)
            if root.right:
                ans.append(root.right)
        
        root=process(root)
        if root:
            ans.append(root)
        return ans

