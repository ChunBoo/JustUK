# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return 

        while root:
            if p.val<root.val and q.val<root.val:
                root=root.left
            elif p.val>root.val and q.val>root.val:
                root=root.right
            else:
                break;
        return root
    def lowestCommonAncestor2(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def f(root,p,q):
            if not root:
                return 
            if p.val<root.val and q.val<root.val:
                return f(root.left,p,q)
            elif p.val>root.val and q.val>root.val:
                return  f(root.right,p,q)
            else:
                return root
        return f(root,p,q)
    

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution2:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parent = {}
        def dfs(root, par):
            nonlocal parent
            if not root:
                return
            dfs(root.left, root)
            dfs(root.right, root)            
            parent[root] = par
            
        dfs(root, None)
        seen = set()
        for k,v in parent.items():
            if k and v:
                print(k.val,v.val)
        while p:      
            seen.add(p)            
            p = parent[p]
        
        while q: 
            if q in seen:
                return q
            q = parent[q]
        return None
    
    
six=TreeNode(6)
seven=TreeNode(7)
four=TreeNode(4)
five=TreeNode(5)
three=TreeNode(3)
two=TreeNode(2)
one=TreeNode(1)
eight=TreeNode(8)

two.left=one
two.right=three
five.left=four
five.right=six
four.left=two
seven.left=five

seven.right=eight

# print(Solution().lowestCommonAncestor(seven, one, three).val)
print(Solution2().lowestCommonAncestor(seven, one, three).val)