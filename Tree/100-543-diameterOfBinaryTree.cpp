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
/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/
class Solution {
public:
    int dfs(TreeNode* root,int &ans)
    {
        if(!root->left&&!root->right)
            return 0;

        int leftLen=root->left?dfs(root->left,ans)+1:0;
        int rightLen=root->right?dfs(root->right,ans)+1:0;
        ans=max(ans,leftLen+rightLen);
        return max(leftLen,rightLen);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};