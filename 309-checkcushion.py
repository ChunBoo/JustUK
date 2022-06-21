from treeNode import TreeNode
from collections import deque
def checkcusin_BFS(root,x,y):
    data={
        x:{"level":None,"parent":None},
        y:{"level":None,"parent":None},
    }
    q=deque([(root,None,0)])
    
    while len(q):       
        if data[x]['level'] and data[y]['level']:
            break
        t=len(q)
        for _ in range(t):
            cur,p,lvl=q.popleft()
            if cur.val in data:
                data[cur.val]["level"]=lvl
                data[cur.val]["parent"]=p

            if cur.left:
                q.append([cur.left,cur,lvl+1])
            if cur.right:
                q.append([cur.right,cur,lvl+1])  
            
    return data[x]["level"]==data[y]["level"] and \
        data[x]["parent"]!=data[y]["parent"]
    
def checkcusin(root,x,y):
    data={
        x:{"level":None,"parent":None},
        y:{"level":None,"parent":None},
    }
    def dfs(root,level,parent):
        if not root:
            return
        if root.val in data:
            data[root.val]["level"]=level
            data[root.val]["parent"]=parent
        if data[x]['level'] and data[x]['level']:
            return
        if root.left:
            dfs(root.left,level+1,root)
        if root.right:
            dfs(root.right,level+1,root)
    dfs(root,0,None)
    return data[x]["level"]==data[y]["level"] and \
            data[x]["parent"]!=data[y]["parent"]
            
            
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