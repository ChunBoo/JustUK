

class TreeNode:
    def __init__(self,val) -> None:
        self.val=val
        self.left=None
        self.right=None
        


def kthSmallestNode(root,k):
    if k<0:
        return None
    ans=0
    count=lambda x:count(x.left)+count(x.right)+1 if x else 0
    leftCnt=count(root.left)
    if leftCnt==k-1:
        return root.val
    if leftCnt>=k:
        return kthSmallestNode(root.left,k)
    return kthSmallestNode(root.right,k-1-leftCnt)
        


def smallNodeWithDFS(root,k):
    if k<0 or not root:
        return None
    
    def dfs(root):
        nonlocal k  #nonlocal声明的变量不是局部变量,也不是全局变量,而是外部嵌套函数内的变量。
        if k<0 or not root:
            return 
        dfs(root.left)
        k-=1
        if k==0:
            return root.val
        dfs(root.right)
    return dfs(root)

root=TreeNode(2)
left=TreeNode(1)
right=TreeNode(3)
root.left=left
root.right=right

# print(kthSmallestNode(root,2))
print(smallNodeWithDFS(root,2))