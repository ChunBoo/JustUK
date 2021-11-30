#ifndef TREE_NODE_H
#define TREE_NODE_H
#include<iostream>
class TreeNode
{
    public:
        int m_val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val):m_val{val},left{nullptr},right{nullptr}{};
        TreeNode*  addLeftChild(int val)
        {
            TreeNode* newNode=new TreeNode(val);
            this->left=newNode;
            return newNode;
        }

        TreeNode* addRightChild(int val)
        {
            TreeNode* newNode=new TreeNode(val);
            this->right=newNode;
            return newNode;
        }

        void printTreeInOrder(TreeNode* root)  //left-->root->right
        {
            if(!root)
                return ;
            printTreeInOrder(root->left);
            std::cout<<root->m_val<<'-';
            printTreeInOrder(root->right);
        }
        void printTreeNodePreOrder(TreeNode* root)
        {
            if(!root)
                return;
            std::cout<<root->m_val<<'-';
            printTreeNodePreOrder(root->left);
            printTreeNodePreOrder(root->right);
        }
};

#endif 