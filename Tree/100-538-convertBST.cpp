#include "treeNode.h"
#include<iostream>

using std::cout;

TreeNode* dfs(TreeNode *root,int &num)
{
    if(!root)
        return nullptr;
    dfs(root->right,num);
    num+=root->m_val;
    root->m_val=num;
    dfs(root->left,num);
    return root;
}

TreeNode *convertBST(TreeNode *root)
{
    if(!root)
        return nullptr;
    
    int num=0;
    dfs(root,num);
    return root;
}

int main()
{
    TreeNode *one=new TreeNode(1);
    TreeNode *two=new TreeNode(2);
    TreeNode *three=new TreeNode(3);
    TreeNode *four=new TreeNode(4);
    TreeNode *five=new TreeNode(5);

    three->left=two;
    two->left=one;

    three->right=four;
    four->right=five;
    three->printTreeNodePreOrder(three);
    cout<<"----------------\n";
    TreeNode *newRoot=convertBST(three);
    newRoot->printTreeNodePreOrder(newRoot);
}