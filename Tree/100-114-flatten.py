'''
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 '''
class TreeNode:
    def __init__(self,val,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
         
        
class Solution:
    def flatten(self, root):
        curr = root
        while curr:
            if curr.left:
                predecessor = nxt = curr.left
                while predecessor.right:
                    predecessor = predecessor.right
                predecessor.right = curr.right
                curr.left = None
                curr.right = nxt
            curr = curr.right
    
    def flatten2(self,root):
        nodes=[]
        def preOrder(root):
            if not root:
                return
            nodes.append(root.val)    
            preOrder(root.left)
            preOrder(root.right)
        preOrder(root)
        n=len(nodes)
        pre=TreeNode(nodes[0])
        root.right=pre
        root=root.right
        for i in range(1,n):
            cur=nodes[i]
            curNode=TreeNode(cur)
            pre.right=curNode
            pre=pre.right
            
one=TreeNode(1)
two=TreeNode(2)
three=TreeNode(3)
four=TreeNode(4)
five=TreeNode(5)
six=TreeNode(6)

one.left=two
one.right=three
two.left=four
two.right=five
three.right=six

# Solution().flatten(one)
Solution().flatten2(one)

while one:
    print(one.val)
    one=one.right

