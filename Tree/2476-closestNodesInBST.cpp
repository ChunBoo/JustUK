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
    vector<int> m_data;
    void preTraverse(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
            preTraverse(root->left);
        m_data.push_back(root->val);
        if(root->right)
            preTraverse(root->right);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        if(!root)
            return {{-1,-1}};
        preTraverse(root);
        for(auto i:m_data)
            cout<<i<<',';
        vector<vector<int>> ans;
        for(auto &v:queries){
            vector<int> cur{-1,-1};
            auto left=upper_bound(m_data.begin(),m_data.end(),v);
            if(left!=m_data.begin())
                cur[0]=*prev(left);
            auto right=lower_bound(m_data.begin(),m_data.end(),v);
          
            if(right!=m_data.end())
                cur[1]=*right;
            ans.push_back(std::move(cur));
        }
        return ans;
    }
};


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
    vector<int> m_data;
    void preTraverse(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
            preTraverse(root->left);
        if(m_data.empty()||root->val>m_data.back())
            m_data.push_back(root->val);
        if(root->right)
            preTraverse(root->right);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        if(!root)
            return {{-1,-1}};
        preTraverse(root);
        vector<vector<int>> ans;
        for (const int q : queries) {
      vector<int> cur{-1, -1};      
      auto it = lower_bound(begin(m_data), end(m_data), q);
      if (it != end(m_data) && *it == q)
        cur[0] = cur[1] = q;
      else {
        if (it != begin(m_data)) cur[0] = *prev(it);
        if (it != end(m_data)) cur[1] = *it;        
      }
      ans.push_back(std::move(cur));
        // for(auto &v:queries){
        //     vector<int> cur{-1,-1};
        //     auto left=lower_bound(begin(m_data),end(m_data),v);
        //     if(*left==v&&left!=end(m_data))
        //         cur[0]=cur[1]=v;
        //     else{
        //     if(left!=begin(m_data))
        //         cur[0]=*prev(left);
        //     if(left!=end(m_data))
        //         cur[1]=*left;
        //     }
        //     ans.push_back(std::move(cur));
        }
        return ans;
    }
};