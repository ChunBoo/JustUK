#include"treeNode.h"
#include<iostream>
#include<map>
using DT=std::map<int,TreeNode*>;

void dfs2(TreeNode*)

void dfs(TreeNode* root,int level,DT& m)
{


}

TreeNode* getLeftBottomNodeInBT(TreeNode* root)
{
    if(!root)
        return nullptr;
    
    
}

int main()
{
    TreeNode* root=new TreeNode(2);
    TreeNode* left=new TreeNode(1);
    left->addLeftChild(99);
    // left->addRightChild(88);
    root->addRightChild(3);
    root->left=left;
    std::cout<<getLeftBottomNodeInBT(root)->m_val;
    return 0;
}