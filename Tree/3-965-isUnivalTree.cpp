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
class Solution {
private:
    int prevVal=-1;
    bool preOrder(TreeNode* root)
    {
        if(!root)
            return true;
        return prevVal==root->val&&preOrder(root->left)&&preOrder(root->right);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;
        prevVal=root->val;
        return preOrder(root);
    }
};