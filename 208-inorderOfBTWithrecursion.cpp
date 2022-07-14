#include<iostream>
#include"treeNode.h"
#include<vector>

using DT=std::vector<int>;


void dfs(TreeNode* root,DT& vec)
{
    if(!root)
        return;
    dfs(root->left,vec);
    vec.push_back(root->m_val);
    dfs(root->right,vec);
}
DT inorderOfBT(TreeNode* root)
{
    DT ans{};
    if(!root)
        return ans;
    dfs(root,ans);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->addLeftChild(2);
    root->addRightChild(3);
    DT res=inorderOfBT(root);
    for(auto i:res)
        std::cout<<i<<',';
    return 0;
}
