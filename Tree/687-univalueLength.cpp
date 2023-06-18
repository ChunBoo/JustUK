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
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        if(!root)
            return ans;
        uniValuePath(root,ans);
        return ans;
    }
private:
    int uniValuePath(TreeNode* root, int& ans)
    {
        if(!root)   
            return 0;
        int l=uniValuePath(root->left,ans);
        int r=uniValuePath(root->right,ans);

        int pl=0,pr=0;

        if(root->left && root->val==root->left->val)
            pl=l+1;
        if(root->right&&root->val==root->right->val)
            pr=r+1;
        ans=max(ans,pl+pr);
        return max(pl,pr);
    }
};