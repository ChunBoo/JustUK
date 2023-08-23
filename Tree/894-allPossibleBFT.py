class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right

def allPossibleFBT(n):
    if n%2==0:
        return []
    if n==1:
        return [TreeNode(0)]
    
    ans=[]
    for i in range(1,n,2):  #here is from 1 to n-1
        for l in allPossibleFBT(i):
           for r in allPossibleFBT(n-i-1):
                root=TreeNode(0)
                root.left=l
                root.right=r

                ans.append(root)
    return ans

# print(allPossibleFBT(7))
res=allPossibleFBT(7)
for n in res:
    print(n.val)

    