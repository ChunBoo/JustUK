

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right



class SS:
    def __init__(self):
        self.ans=[]
    
    def collect(self, root,d):
        if not root or d<0:
            return None
        if d==0:
            self.ans.append(root.val)
        self.collect(root.left, d-1)
        self.collect(root.right,d-1)
    

    def dis(self,root,target,k):
        if not root:
            return 0
        if root==target:
            self.collect(target,k)
            return 0
        l=self.dis(root.left,target,k)
        r=self.dis(root.right,target,k)
        if l>=0:
            if l==k-1:
                self.ans.append(root.val)
            self.collect(root.right,k-l-2)
            return l+1
        if r>=0:
            if r==k-1:
                self.ans.append(root.val)
            self.collect(root.left,k-l-2)
            return r+1
        return -1
        
            

        
    def distanceK(self,root,target,K):
        self.dis(root,target,K)
        return self.ans


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

print(SS().distanceK(root,five,2))