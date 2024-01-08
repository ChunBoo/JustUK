
/**
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
*/
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
    int rob(TreeNode* root) {
        // if(!root) return 0;
        // int ll=root->left?rob(root->left->left):0;
        // int lr=root->left?rob(root->left->right):0;
        // int rl=root->right?rob(root->right->left):0;
        // int rr=root->right?rob(root->right->right):0;
        // return m_[root]=max(root->val+ll+lr+rl+rr,rob(root->left)+rob(root->right));
        int l=0,r=0;
        return rob(root,l,r);
    }

private:
    int rob(TreeNode* root,int& l,int& r)
    {
        if(!root)
            return 0;
        int ll=0,lr=0;
        int rl=0,rr=0;
        l=rob(root->left,ll,lr);
        r=rob(root->right,rl,rr);
        return max(root->val+ll+lr+rl+rr,l+r);
    }
    // unordered_map<TreeNode*,int> m_;
};