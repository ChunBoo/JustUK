//given a BST, find the successor of target node

#include "treeNode.h"
#include<iostream>


int inorderSuccessor(TreeNode* root,int target)
{
    int ans=0;
    if(!root)
        return ans;
    while(root)
    {
        if(target<root->m_val)
        {
            ans=root->m_val;
            root=root->left;
        }
        else
            root=root->right;
    }
    return ans;
}

void inorderSuccessor(TreeNode* root,int target,int& res)
{
    if(!root)
        return ;
    
    int ans=0;
    if(root->m_val>target)
    {
        res=root->m_val;
        inorderSuccessor(root->left,target,res);
    }
    else
        inorderSuccessor(root->right,target,res);
}

int main()
{
    TreeNode* root=new TreeNode(2);
    root->addLeftChild(1);
    root->addRightChild(3);
    int res;
    inorderSuccessor(root,2);
    std::cout<<res<<'\n';
    return 0;
}