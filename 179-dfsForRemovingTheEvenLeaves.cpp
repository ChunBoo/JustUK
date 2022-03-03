//dfs for removing the leaves which value is even
#include"treeNode.h"
#include<iostream>

TreeNode* dfs(TreeNode* root)
{
    if(!root)
        return nullptr;
    
    if(root->left)
        root->left=dfs(root->left);
    if(root->right)
        root->right=dfs(root->right);
    
    if(!root->left&&!root->right)
    {
        if(root->m_val%2==0)
        {
            return nullptr;
        }
    }
    return root;
}

int main()
{
    TreeNode* r1=new TreeNode(5);
    TreeNode* l1=new TreeNode(3);
    TreeNode* r11=new TreeNode(2);
    r1->left=l1;
    r1->right=r11;
    r1->printTreeInOrder(r1);
    std::cout<<'\n';
    TreeNode* r2=dfs(r1);
    r2->printTreeInOrder(r2);
    return 0;
}