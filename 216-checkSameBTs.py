from treeNode import TreeNode

def same(s,t):
    if(s is None and t is None):
        return True
    if(s is None or t is None):
        return False
    
    if(s.val!=t.val):
        return False    

    return same(s.left,t.left) and same(s.right,t.right)

s=TreeNode(1)
t=TreeNode(1)

print(same(s,t))