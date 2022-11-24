
class TreeNode:
    def __init__(self,val,left=None,right=None) -> None:
        self.val=val
        self.left=left
        self.right=right
        


def conversion(root):
    nodes=[]
    
    def dfs(root):
        if not root:
            return []
        return dfs(root.left)+[root.val]+dfs(root.right)
    ans=cur=TreeNode(-1)
    for v in dfs(root):
        cur.right=TreeNode(v)
        cur=cur.right
        
    return ans.right
    

root=TreeNode(2)
left=TreeNode(1)
right=TreeNode(3)
root.left=left
root.right=right
res=conversion(root)
print(res)