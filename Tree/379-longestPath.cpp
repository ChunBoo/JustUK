#include"../treeNode.h"
#include<iostream>


int foo(TreeNode* root,int &ans)
{
    if(!root)
        return 0;
    
    int l=foo(root->left,ans);
    int r=foo(root->right,ans);
    ans=std::max(ans,1+l+r);
    return std::max(l,r)+1;
}

int longestPath(TreeNode* root)
{
    if(!root)
        return 0;
    int ans=0;
    foo(root,ans);
    return ans;
}

int main()
{
    TreeNode *one=new TreeNode(1);
TreeNode* two=new TreeNode(2);
TreeNode* three=new TreeNode(3);
TreeNode* four=new TreeNode(4);
TreeNode *five=new TreeNode(5);
TreeNode *six=new TreeNode(6);
TreeNode *nine=new TreeNode(9); 


one->left=two;
one->right=three;

two->left=six;
three->left=four;
three->right=nine;
four->right=five;

std::cout<<longestPath(one);
}