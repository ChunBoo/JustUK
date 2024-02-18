#include "treeNode.h"
#include<iostream>
#include<vector>
#include<deque>
using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using Q=std::deque<TreeNode*>;
class Solution {
public:
    MATRIX levelOrder(TreeNode* root) {
      MATRIX ans{};
      if(!root)
        return ans;
      Q q{};
      q.push_back(root);
      while(!q.empty())
      {
        int sz=q.size();
        VEC tmp{};
        for(int i=0;i<sz;++i)
        {
            TreeNode* node=q.front();
            q.pop_front();
            tmp.push_back(node->m_val);
            if(node->left)
                q.push_back(node->left);
            if(node->right)
                q.push_back(node->right);
        }
        ans.push_back(tmp);
      }
      return ans;
    }
};

/**
 * @brief 20240214 added the DFS method
 * 
 * @return int 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, int depth,vector<vector<int>>& ans){
        if(!root)
            return;
        while(ans.size()<=depth)
            ans.push_back({});
        
        dfs(root->left,depth+1,ans);
        dfs(root->right,depth+1,ans);
        ans[depth].push_back(root->val);

    }
};

int main()
{
    TreeNode *root=new TreeNode(1);
    TreeNode *two=new TreeNode(2);
    TreeNode *three=new TreeNode(3);
    TreeNode *four=new TreeNode(4);
    TreeNode *five=new TreeNode(5);
    root->left=two;
    root->right=three;
    two->right=four;
    three->left=five;

    MATRIX res=Solution().levelOrder(root);
    for(auto &v:res)
    {
        cout<<"\n";
        for(auto &d:v)
            cout<<d<<',';
    }
}