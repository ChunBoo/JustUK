class TreeNode:
    def __init__(self,val,left=None,right=None) -> None:
        self.val=val
        self.left=left
        self.right=right



ans=0     
def dfs(root):
    if not root:
        return 0
    
    l=dfs(root.left)
    r=dfs(root.right)
    # nonlocal ans
    ans=max(ans,1+r+l)
    return max(l,r)+1



def longestPath(root):
    if not root:
        return 0
    
    dfs(root)
    # nonlocal ans
    return ans


one=TreeNode(1)
two=TreeNode(2)
three=TreeNode(3)
four=TreeNode(4)
five=TreeNode(5)
six=TreeNode(6)
nine=TreeNode(9) 


one.left=two
one.right=three

two.left=six
three.left=4
three.right=9
four.right=5

print(longestPath(one))   