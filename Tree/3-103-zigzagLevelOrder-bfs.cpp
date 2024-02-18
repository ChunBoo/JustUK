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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        bool left2right=true;
        while(!q.empty()){
            int sz=q.size();
            vector<int> tmp(sz);
            int i=sz;
            for(int i=0;i<sz;++i){
                TreeNode* cur=q.front();
                q.pop();
                int idx=left2right?i:sz-i-1;
                tmp[idx]=(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            
            ans.push_back(tmp);
            left2right=!left2right;
        }
        return ans;
    }
};