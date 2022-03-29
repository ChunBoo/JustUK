#include"treeNode.h"
#include<iostream>
#include<map>
using DT=std::map<int,TreeNode*>;


void dfs(TreeNode* root,int level,DT& m)
{
    if(!root)
        return ;
    
    m.insert({level,root});
    dfs(root->left,level+1,m);
    dfs(root->right,level+1,m);
}

TreeNode* getLeftBottomNodeInBT(TreeNode* root)
{
    if(!root)
        return nullptr;
    
    DT m{{0,root}};
    dfs(root,0,m);    
    int maxLevel=0;
    TreeNode* ans;
    for(auto i:m)
    {
        if(i.first>maxLevel)
        {
            maxLevel=i.first;
            ans=i.second;
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