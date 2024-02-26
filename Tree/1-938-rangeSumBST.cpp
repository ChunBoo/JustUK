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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        // vector<int> order;
        int ans=0;

        preOrder(root, ans,low,high);

        return ans;
    }
private:
    void preOrder(TreeNode* root,int& ans,int low,int high)
    {
        if(!root)
            return;
        preOrder(root->left,ans,low,high);
        if(root->val>=low&&root->val<=high)
            ans+=root->val;
        preOrder(root->right,ans,low,high);
    }
};