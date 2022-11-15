'''
the root of a binary tree, collect a tree’s nodes as if you were doing this:
Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
'''
from collections import defaultdict
# class CNode:
#     def __init__(self,val,left=None,right=None):
#         self.val=val
#         self.left=left
#         self.right=right
    
#     def addLeft(self,left):
#         self.left=left
    
#     def addRight(self,right):
#         self.right=right
#     def getLeft(self):
#         return self.left
#     def getRight(self):
#         return self.right
#     def getVal(self):
#         return self.val
class CNode:
    def __init__(self,val,left=None,right=None) -> None:
        self.val=val
        self.left=left
        self.right=right    

class Solution:
    def findLeaves(self,root):
        data=defaultdict(list)
        
        def dfs(root):
            if not root:
                return 0
            
            left=dfs(root.left)
            right=dfs(root.right)
            
            depth=max(left,right)+1
            data[depth].append(root.val)
            return depth
        dfs(root)
        return data.values()
    

root=CNode(0)
one=CNode(1)
two=CNode(2)
three=CNode(3)
four=CNode(4)

root.left=one
root.right=three
one.left=two
one.right=four
s=Solution()
print(s.findLeaves(root))