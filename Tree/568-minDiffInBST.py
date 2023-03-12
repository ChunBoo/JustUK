# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        ans=inf
        prev=None
        def dfs(root):
            if not root:
                return 
            dfs(root.left)
            nonlocal prev,ans
            if prev:
                ans=min(ans,root.val-prev.val)
            prev=root
            dfs(root.right)
        dfs(root)
        return ans


        # nums=[]
        # ans=inf
        # def inorder(root):
        #     if not root:
        #         return 

        #     inorder(root.left)
        #     nums.append(root.val)
        #     inorder(root.right)
        
        # inorder(root)
        # for i in range(1,len(nums)):
        #     ans=min(ans,nums[i]-nums[i-1])
        # return ans
