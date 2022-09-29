"""
Given a binary tree root, return the longest path consisting of even values between any two nodes in the tree.
"""


class Tree:
    def __init__(self,val,left=None,right=None) -> None:
        self.val=val
        self.left=left
        self.right=right
        
    

class Solution:
    def longestEvenPathNodesCount(self,root):
        if not root:
            return 0
        
        ans=0
        tmpList=[]
        def dfs(root):
            if not root:
                return 0
            nonlocal ans
            l=dfs(root.left)
            r=dfs(root.right)
            if  root.val&1==0:
                ans=max(ans,l+r+1)
                tmpList.append(root.val)
                return 1+max(l,r)
            return 0
            
        dfs(root)
        print(tmpList)
        return ans
    
    
root=Tree(0)
left1=Tree(8)
right1=Tree(2)

rLeft2=Tree(6)
rright2=Tree(0)
rLeft3=Tree(4)

root.left=left1
root.right=right1

right1.left=rLeft2
right1.right=rright2

rLeft2.left=rLeft3

s=Solution()
print(s.longestEvenPathNodesCount(root))
                