'''
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, 
then right to left for the next level and alternate between).
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        if not root.left and not root.right:
            return [[root.val]]
        ans=[]
        
        q=deque([root])
        while q:
            n=len(q)
            tmp=[]
            for _ in range(n):
                cur=q.popleft()
                tmp.append(cur.val)

                for kid in(cur.left,cur.right):
                        if kid:
                            q.append(kid)
            if len(ans)&1:
                ans.append(tmp[::-1])
            else:
                ans.append(tmp)
        return ans



        # while q:
        #     tmp=[]
        #     n=len(q)
        #     for i in range(n):
        #         cur,lel=q.popleft()
        #         if not cur:
        #             continue
        #         tmp.append(cur.val)
        #         if lel&1:
        #                 q.append((cur.left,lel+1))
        #                 q.append((cur.right,lel+1))
        #         else:
        #                 q.append((cur.right,lel+1))
        #                 q.append((cur.left,lel+1))
        #     if tmp:
        #         ans.append(tmp)
        # return ans