
from treeNode import TreeNode

def kthSmallest(root,k):#iterator
    s=[]
    if not root:
        return 
    cnt=0
    # s.append(root)
    p=root
    while len(s) or p:
        if p:
            s.append(p)
            p=p.left
        
        else:
            p=s.pop()
            cnt+=1
            if k==cnt:
                return p.val
            p=p.right
        
    
def kthSmallest2(root,k):
    data=[]
    def dfs(root):
        if not root:
            return 
        dfs(root.left)
        data.append(root.val)
        dfs(root.right)
    
    dfs(root)
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

print(kthSmallest(root, 3))
