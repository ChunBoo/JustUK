#include<iostream>
#include"treeNode.h"


bool dfs(TreeNode* root)
{

    if(!root)
        return true;
    int sum=0;
     bool ans=true;
    if(root->left)
    {
        sum+=root->left->m_val;
        ans=ans&&dfs(root->left);
    }
    if(root->right)
    {
        sum+=root->right->m_val;
        ans=ans&&dfs(root->right);
    }
    if(root->left||root->right)
        if(sum!=root->m_val)    
            return false;
    return ans;
}

int main()
{
            TreeNode* r1=new TreeNode(5);
    TreeNode* l1=new TreeNode(3);
    TreeNode* r11=new TreeNode(2);
    r1->left=l1;
    r1->right=r11;
    std::cout<<dfs(r1)<<'\n';
    return 0;
}