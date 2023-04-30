class CNode:
    def __init__(self,val,left=None,right=None) -> None:
        self.val=val
        self.left=left
        self.right=right    
        
        
def mergeTress(r1,r2):
    if not r1:
        return r2
    if not r2:
        return r1
    r1.val+=r2.val
    
    r1.left=mergeTress(r1.left, r2.left)
    r1.right=mergeTress(r1.right, r2.right)
    return r1

r1=CNode(1)
l1=CNode(2)
r1=CNode(3)

r1.left=l1
r1.right=r1

r2=CNode(1)
l2=CNode(2)
r2=CNode(3)
r2.left=l2
r2.right=r2

nr=mergeTress(r1, r2)
print(nr.val,nr.left.val,nr.right.val)

