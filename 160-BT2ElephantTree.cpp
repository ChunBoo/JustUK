//convert a Binary tree to an elephant tree


#include"treeNode.h"
#include<iostream>

int dfs(TreeNode* root)
{
    if(!root)
        return 0;
    
    int ans=root->m_val;

    if(root->left)
        ans+=dfs(root->left);
    if(root->right)
        ans+=dfs(root->right);
    
    root->m_val=ans;
    return ans;
}

void BT2ElephantTree(TreeNode* root)
{
    if(!root)
        return;
    dfs(root);
}


int main()
{
    TreeNode* root= new TreeNode(1);
    TreeNode* left= new TreeNode(2);
    TreeNode* left2= new TreeNode(4);
    TreeNode* right= new TreeNode(3);
    TreeNode* right2= new TreeNode(5);
    
    left->left=left2;
    right->left=right2;

    root->left=left;
    root->right=right;
    root->printTreeInOrder(root);

    BT2ElephantTree(root);;
    std::cout<<'\n';
    root->printTreeInOrder(root);
    return 0;
}