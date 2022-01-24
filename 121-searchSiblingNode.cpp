//given a BST,search one's nodes sibling nodes

#include"treeNode.h"
#include<iostream>

TreeNode* getSiblingNode(TreeNode* root, int value)
{
    TreeNode* retNode=nullptr;
    if(!root)
        return retNode;

    while(root)
    {
        if(root->m_val==value)
            return retNode;
        if(root->m_val<value)
        {
            retNode=root->left;
            root=root->right;
        }
        else
        {
            retNode=root->right;
            root=root->left;
        }
    }
    return retNode;
}

int main()
{
     TreeNode* root=new TreeNode(6);
    TreeNode* left=new TreeNode(5);
    left->addLeftChild(4);
    root->left=left;
    root->addRightChild(8);

    TreeNode* res=getSiblingNode(root,8);
    if(res)
        std::cout<<res->m_val<<'\n';
    return 0;
}