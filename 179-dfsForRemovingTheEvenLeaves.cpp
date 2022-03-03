//dfs for removing the leaves which value is even
#include"treeNode.h"
#include<iostream>

void dfs(TreeNode* root)
{
    if(!root)
        return ;
    
    if(root->left)
        dfs(root->left);
    if(root->right)
        dfs(root->right);
    
    if(!root->left&&!root->right)
    {
        if(root->m_val%2==0)
        {
            delete root;
            root=nullptr;
        }
    }
}

int main()
{
    TreeNode* r1=new TreeNode(5);
    TreeNode* l1=new TreeNode(3);
    TreeNode* r11=new TreeNode(2);
    r1->left=l1;
    r1->right=r11;
    r1->printTreeInOrder(r1);

    dfs(r1);
    r1->printTreeInOrder(r1);
    return 0;
}