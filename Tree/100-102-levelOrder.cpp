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