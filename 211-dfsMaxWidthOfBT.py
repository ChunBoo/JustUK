

from treeNode import TreeNode

def maxWidth(root):
    if(root==None):
        return 0
    data={}
    
    def dfs(root,v,level):
        if(root==None):
            return 

        if level in data:
            data[level][0]=min(data[level][0],v)
            data[level][1]=max(data[level][1],v)

        else:
            data[level]=[v,v]
        if(root.left!=None):
            dfs(root.left,v*2,level+1)
        if(root.right!=None):
            dfs(root.right,v*2+1,level+1)
    
    dfs(root,0,0)
    return max(R-L+1 for L,R in data.values())


root=TreeNode(1)
root.left=TreeNode(2)
root.right=TreeNode(3)
root.left.left=TreeNode(4)
root.right.right=TreeNode(5)
print(maxWidth(root))
