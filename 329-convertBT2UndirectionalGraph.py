from treeNode import TreeNode
from collections import defaultdict
from collections import deque
def convert(root):
    G=defaultdict(list)
    
    def dfs(root,parent):
        if not root:
            return 
        if parent:
            G[root.val].append(parent.val)
            G[parent.val].append(root.val)

        dfs(root.left,root)
        dfs(root.right,root)
        
    dfs(root,None)
    return G

def convert_bfs(root):
    G=defaultdict(list)
    q=deque([(root,None)])
    
    while q:
        cur,parent=q.popleft()
        if not cur:
            continue
        if parent:
            G[cur.val].append(parent.val)
            G[parent.val].append(cur.val)
        q.append([cur.left,cur])
        q.append([cur.right,cur])
        
    return G


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

res=convert(root)
res2=convert_bfs(root)
for k,v in res2.items():
    print(k,"-->",v)