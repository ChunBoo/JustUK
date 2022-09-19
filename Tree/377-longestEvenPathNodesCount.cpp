#include "../treeNode.h"
#include<iostream>

int dfs(TreeNode* root,int &val)
{
    if(!root)
        return 0;
    
    int l=dfs(root->left, val);
    int r=dfs(root->right,val);
    if(root->m_val&1==0)  //even node
    {
        val=std::max(val,l+r+1);
        return std::max(l,r)+1;
    }
    return 0;
}

int getLongestEvenPathNodesCount(TreeNode* root)
{
    if(!root)
        return 0;
    
    int ans=0;
    dfs(root,ans);
    return ans;
}

int main()
{
TreeNode *root=new TreeNode(0);
TreeNode *left1=new TreeNode(8);
TreeNode *right1=new TreeNode(2);

TreeNode *rLeft2=new TreeNode(6);
TreeNode *rright2=new TreeNode(0);
TreeNode *rLeft3=new TreeNode(4);

root->left=left1;
root->right=right1;

right1->left=rLeft2;
right1->right=rright2;

rLeft2->left=rLeft3;

std::cout<<getLongestEvenPathNodesCount(root);
}