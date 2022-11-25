

class TreeNode:
    def __init__(self,val) -> None:
        self.val=val
        self.left=None
        self.right=None
        


def kthSmallestNode(root,k):
    if k<0:
        return None
    ans=0
    nonlocal ans
    def dfs(root):
        if k<0:
            return 
        dfs(root.left)
        k-=1
        if k==0:
            ans=root.val
            return ans
        dfs(root.right)
        
    dfs(root)
    return ans