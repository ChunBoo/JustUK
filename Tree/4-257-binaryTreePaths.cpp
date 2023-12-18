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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr;
        preorder(root,ans,curr,0);
        // for(auto)
        return ans;
    }
private:
    void preorder(TreeNode* root,vector<string>& ans, string& curr,int l)
    {
        if(!root)
            return;
        curr+=(l>0?"->":"")+to_string(root->val);
        if(root->left==nullptr&&root->right==nullptr)
            ans.push_back(curr);
        // curr+="->";
        preorder(root->left,ans,curr,curr.size());
        preorder(root->right,ans,curr,curr.size());
        while(curr.size()>l) curr.pop_back();
    }
};