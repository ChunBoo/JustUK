//trim a BST 

#include "treeNode.h"
#include <iostream>

TreeNode* trimBST(TreeNode* root,int lo,int hi)
{
    if(!root)
        return root;
    
    if(root->m_val<lo)
        return trimBST(root->right,lo,hi);
    if(root->m_val>hi)
        return trimBST(root->left,lo,hi);
    root->left=trimBST(root->left,lo,hi);
    root->right=trimBST(root->right,lo,hi);

    return root;
}

int main()
{
    TreeNode* root=new TreeNode(6);
    TreeNode* left=new TreeNode(4);
    TreeNode* right=new TreeNode(8);

    left->addLeftChild(3);
    left->addRightChild(5);

    right->addLeftChild(7);
    right->addRightChild(9);
    root->left=left;
    root->right=right;
    root->printTreeInOrder(root);
    std::cout<<"\n";
    TreeNode* newRoot=trimBST(root,4,6);   //include [4,5]
    newRoot->printTreeInOrder(newRoot);
    return 0;
}