
from treeNode import TreeNode

def kthSmallest_iterator(root,k):#iterator method uses stack to implement
    stack=[]   # pop(),append()
    if(not root):
        return
    p=root
    while(stack or p):
        while(p):
            stack.append(p)
            p=p.left
        p=stack.pop()
        k-=1
        if k==0:
            return p.val
        p=p.right        

def kthSmallest_iterator2(root,k):#iterator method uses stack to implement
    stack=[]   # pop(),append()
    if(not root):
        return
    p=root
    cnt=0
    while(stack or p):
        if(p):
            stack.append(p)
            p=p.left
        else:
            p=stack.pop()
            cnt+=1
            if k==cnt:
                return p.val
            p=p.right       
        
    
def kthSmallest_dfs(root,k):
    data=[]
    def dfs(root):
        if not root:
            return 
        dfs(root.left)
        data.append(root.val)
        dfs(root.right)
    dfs(root)
    return data[k-1]

def kthSmallest_dfs2(root,k):
    # data=[]
    def dfs(root):
        if not root:
            return []
        return dfs(root.left)+[root.val]+dfs(root.right)
        # data.append(root.val)
    data=dfs(root)
    return data[k-1]


root=TreeNode(5)
left=TreeNode(3)
left2=TreeNode(2)
right2=TreeNode(4)

right=TreeNode(7)
rleft=TreeNode(6)
rright=TreeNode(8)
root.left=left
root.right=right
left.left=left2
left.right=right2

right.left=rleft
right.right=rright

# print(kthSmallest(root, 3))
# print(kthSmallest_dfs(root, 3))
print(kthSmallest_dfs2(root, 3))
print(kthSmallest_iterator2(root, 3))
