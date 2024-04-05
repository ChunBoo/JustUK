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
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        dfs(root,  ans);
        return ans;
    }
private:
    // void dfs(TreeNode* root, int mn, int mx, int& ans)
    // {
    //     if(!root)
    //         return ;
    //     mn=min(mn, root->val);
    //     mx=max(mx,root->val);

    //     ans=max(ans,max(root->val-mn, mx-root->val));
    //     dfs(root->left,mn,mx,ans);
    //     dfs(root->right,mn,mx,ans);
    // }
    pair<int,int> dfs(TreeNode* node,int& ans){
        if(!node)
            return {INT_MAX,INT_MIN};

        auto [lMin,lMax]=dfs(node->left,ans);
        auto [rMin,rMax]=dfs(node->right,ans);

        int mn=min(node->val, min(lMin,rMin));
        int mx=max(node->val, max(lMax,rMax));

        ans=max(ans,max(node->val-mn, mx-node->val));
        return {mn,mx};
    }
};