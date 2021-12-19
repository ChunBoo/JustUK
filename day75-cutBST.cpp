// cut/trim BST

#include"treeNode.h"
#include<iostream>

TreeNode* cutBST(TreeNode* root,int L,int R)
{
   if(!root)
    return root;

   if(root->m_val<L)
   {
       return cutBST(root->right,L,R);
   }
   if(root->m_val>R)
    return  cutBST(root->left,L,R);

   root->left=cutBST(root->left,L,R);
   root->right=cutBST(root->right,L,R);

   return root; 
}


int main()
{
    TreeNode* root= new TreeNode(4);
    TreeNode* left=new TreeNode(2);
    left->addLeftChild(1);
    left->addRightChild(3);
    root->left=left;

    TreeNode* right=new TreeNode(6);
    right->addLeftChild(5);
    right->addRightChild(7);
    root->right=right;

    root->printTreeInOrder(root);
    std::cout<<'\n';
    TreeNode* newRoot=cutBST(root,3,6);
    newRoot->printTreeInOrder(newRoot);
    return 0;
}