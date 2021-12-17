//recursion to get the binary tree's max depth

#include<iostream>
#include"treeNode.h"
#include<cmath>
int maxDepth(TreeNode* root)
{
    if(!root)
        return 0;
    
    int l=maxDepth(root->left)+1;
    int r=maxDepth(root->right)+1;
    return std::max(l,r);
}


int main()
{
    TreeNode* root=new TreeNode(6);
    // root->addLeftChild(2);
    TreeNode*  left=new TreeNode(5);
    left->addLeftChild(3);
    root->left=left;

    int depth=maxDepth(root);
    std::cout<<"Max depth is: "<<depth<<'\n';

    return 0;   
}