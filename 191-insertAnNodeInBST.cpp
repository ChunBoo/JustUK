#include"treeNode.h"
#include<iostream>

TreeNode* insertNewNodeToBST(TreeNode* root,int val)
{
    if(!root)
        return new TreeNode(val);
    if(root->m_val<val)
        root->right=insertNewNodeToBST(root->right,val);
    else    
        root->left=insertNewNodeToBST(root->left,val);

    return root;
}

int main()
{
    TreeNode* root=new TreeNode(2);
    root->addLeftChild(1);
    root->addRightChild(3);
    root->printTreeNodePreOrder(root);
    root=insertNewNodeToBST(root,4);
    root->printTreeNodePreOrder(root);
    return 0;
}