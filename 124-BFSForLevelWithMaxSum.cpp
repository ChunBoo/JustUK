//given a bst,return the level number which it's sum of each nodes is maximum

#include "treeNode.h"
#include<deque>
#include<iostream>

int getMaxLevel(TreeNode* root)
{
    if(!root)
        return 0;
    int ans=0;
    
}


int main()
{
    TreeNode* root=new TreeNode(23);
    TreeNode* l1Left=new TreeNode(2);
    TreeNode* l1right=new TreeNode(3);
    TreeNode* l21left=new TreeNode(4);
    TreeNode* l21right=new TreeNode(5);
    TreeNode* l22left=new TreeNode(6);
    TreeNode* l22right=new TreeNode(7);
    
    l1Left->left=l21left;
    l1Left->right=l21right;
    
    l1right->left=l22left;
    l1right->right=l22right;

    root->left=l1Left;
    root->right=l1right;

    int res=getMaxLevel(root);
    std::cout<<"Max level is: "<<res<<'\n';
    
    return 0;
}
