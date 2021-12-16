#include"treeNode.h"
#include<iostream>

TreeNode* mergeTwoBT(TreeNode* RA,TreeNode* RB)
{
    if(!RA)
        return RB;
    if(!RB)
        return RA;

    TreeNode* newRoot=new TreeNode(RA->m_val+RB->m_val);
    newRoot->left=mergeTwoBT(RA->left,RB->left);
    newRoot->right=mergeTwoBT(RA->right,RB->right);

    return newRoot;
}

int main()
{
    TreeNode* ra=new TreeNode(4);
    ra->addLeftChild(3);
    ra->addRightChild(5);

    TreeNode* rb=new TreeNode(8);
    rb->addLeftChild(7);
    rb->addRightChild(9);

    TreeNode* newRoot=mergeTwoBT(ra,rb);
    newRoot->printTreeInOrder(newRoot);
    return 0;
}