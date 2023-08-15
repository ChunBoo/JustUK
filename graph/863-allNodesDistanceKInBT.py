from collections import deque,defaultdict

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right


def allNodesDistanceWithK(root, target,K):
    seen=set()
    seen.add(target)
    q=deque()
    q.append(target)
    ans=[]
    g=defaultdict(list)
    def buildGraph(parent,child):
        if parent:
            g[parent].append(child)
            g[child].append(parent)
        if child.left:
            buildGraph(child, child.left)
        if child.right:
            buildGraph(child, child.right)

    
    buildGraph(None,root)
    k=0
    while q and k<=K:
        sz=len(q)
        while sz:
            cur=q[0]
            q.popleft()
            if k==K:
                ans.append(cur.val)
            for nxt in g[cur]:
                if nxt in seen:
                    continue
                seen.add(nxt)
                q.append(nxt)
            sz-=1
        k+=1
    
    return ans

root = TreeNode(3)
one = TreeNode(1)
two = TreeNode(2)
four = TreeNode(4)
five = TreeNode(5)
six = TreeNode(6)
seven = TreeNode(7)

root.left = five
root.right = one
five.left = six
five.right = seven
seven.left = two
seven.right = four

print(allNodesDistanceWithK(root,five,2))
