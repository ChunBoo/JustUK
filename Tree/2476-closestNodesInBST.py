from bisect import bisect_left,bisect_right

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
        

def closetNodes(root,queries):
    if not root:
        return [[]]
    n=len(queries)
    ans=[]
    vals=[]
    def inTraverse(root):
        if not root:
            return
        inTraverse(root.left)
        if len(vals)==0 or root.val>vals[-1]:
            vals.append(root.val)
        inTraverse(root.right)
    inTraverse(root)
    for v in queries:
        cur=[-1,-1]
        idx=bisect_left(vals,v)
        if idx<=len(vals)-1 and vals[idx]==v :
            cur[0]=cur[1]=v
        else:
            if idx>0:
                cur[0]=vals[idx-1]
            if idx<=len(vals)-1:
                cur[1]=vals[idx]
        ans.append(cur)
    return ans


root = TreeNode(6)
one = TreeNode(1)
five = TreeNode(5)
four = TreeNode(4)
seven = TreeNode(7)
nine = TreeNode(9)
ten = TreeNode(10)

root.left = four
root.right = nine
four.left = one
four.right = five

nine.left = seven
nine.right = ten
q=[2, 4, 16]
print(closetNodes(root,q))