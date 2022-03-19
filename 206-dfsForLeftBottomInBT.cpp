#include"treeNode.h"
#include<iostream>
#include<map>
using DT=std::map<int,TreeNode*>;
void dfs(TreeNode* root,int level,DT& m)
{
    if(!root)
        return ;
    if(root->left)
       dfs(root->left,level+1,m);
    if(root->right)
        dfs(root->right,level+1,m);
    if(!root->right&&!root->left)
        m.insert({level,root});
}

TreeNode* getLeftBottomNodeInBT(TreeNode* root)
{
    if(!root)
        return nullptr;
    DT m{};
    dfs(root,0,m);
    TreeNode* ans;
    int maxLevel=0;
    for(auto d:m)
    {
        if(d.first>maxLevel)
        {
            maxLevel=d.first;
            ans=d.second;
        }
    }
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(2);
    TreeNode* left=new TreeNode(1);
    // left->addLeftChild(99);
    left->addRightChild(88);
    root->addRightChild(3);
    root->left=left;
    std::cout<<getLeftBottomNodeInBT(root)->m_val;
    return 0;
}