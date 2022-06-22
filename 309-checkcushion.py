from treeNode import TreeNode
from collections import deque
"""_summary_
    BFS/DFS used to iterate total binarytree for some conditions,likes cousin nodes in a binary tree
"""
def checkcusin_BFS(root,x,y):
    data={
        x:{'level':None,"parent":None},
        y:{'level':None,"parent":None},
    }
    if not root:
        return
    q=deque([(root,0,None)])
    
    while q:
        cur,level,parent=q.popleft()
        
        if cur.val in data:
            data[cur.val]['level']=level
            data[cur.val]['parent']=parent
        if(data[x]['level'] and data[y]['level']):
            break
        if cur.left:
            q.append((cur.left,level+1,cur))  #here we should append the list or the tuple as one unit
        if cur.right:
            q.append((cur.right,level+1,cur))
        
    
    return data[x]['level']==data[y]['level'] and data[x]['parent']!=data[y]['parent']
    
    
    
    
    
    
    # q=deque([(root,0,None)])  #cur,level,parent,here should be pay more attention for this initialization：deque([(root,0,None)])
    # q=deque([root,0,None])  #cannot unpack non-iterable TreeNode object
    #deque([[<treeNode.TreeNode object at 0x0000022214A9A190>, 1, <treeNode.TreeNode object at 0x0000022214A9A130>], [<treeNode.TreeNode object at 0x0000022214A9ADC0>, 2, <treeNode.TreeNode object at 0x0000022214A9A160>]])



def checkcousin_dfs(root,x,y):
    data={
        x:{'level':None,"parent":None},
        y:{'level':None, "parent":None}
    }
    
    def dfs(root,level,parent):
        if not root:
            return
        if root.val in data:
            data[root.val]['level']=level
            data[root.val]['parent']=parent
        if(data[x]['level'] and data[y]['level']):
            return 
        dfs(root.left,level+1,root)
        dfs(root.right,level+1,parent)
    
    dfs(root,0,None)
    
    return data[x]['level']==data[y]['level'] and data[x]['parent']!=data[y]['parent']
            
            
root=TreeNode(5)
left1=TreeNode(4)
right1=TreeNode(7)
left21=TreeNode(3)
right22=TreeNode(8)
root.left=left1
root.right=right1
left1.left=left21
right1.right=right22

print(checkcusin_BFS(root, 3, 7))
print(checkcousin_dfs(root,3,7))