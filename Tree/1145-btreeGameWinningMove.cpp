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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        nodes(root,x);
        int p=n-m_r-m_l-1;
        return max(p,max(m_r,m_l))>n/2;
    }
    private:
        int m_l,m_r;
        int nodes(TreeNode* root,int x)
        {
            if(!root)
                return 0;
            int l=nodes(root->left,x);
            int r=nodes(root->right,x);
            if(root->val==x){
                m_l=l;
                m_r=r;
            }
            return l+r+1;
        }
};