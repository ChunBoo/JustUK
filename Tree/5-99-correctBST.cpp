/**
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

/**
 * Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
Solution: Inorder traversal
Using inorder traversal to find two nodes that have val < prev.val

Time complexity: O(n)
Space complexity: O(h)
*/
class Solution {
private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
public:
    void inorder(TreeNode* root)
    {
        if(!root)
            return ;
        inorder(root->left);
        if(prev&&prev->val>root->val)
        {
            if(!first)
                first=prev;
            second=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        inorder(root);
        swap(first->val, second->val);
    }
};