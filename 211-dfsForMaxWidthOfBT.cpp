#include"treeNode.h"
#include<iostream>

#include<vector>
#include<cmath>
void dfs(TreeNode* root, int val,int& max,int& min)
{
    if(!root)
        return ;
    max=std::max(val,max);
    min=std::min(val,min);
    if(root->left)
        dfs(root->left,val*2,max,min);
    if(root->right)
        dfs(root->right,val*2+1,max,min);
}

int dfsForMaxWidth(TreeNode* root)
{
    if(!root)
        return 0;
    int max=INT_MIN, min=INT_MAX;
    dfs(root,0,max,min);
    return max-min+1;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* left=new TreeNode(2);
    TreeNode* right=new TreeNode(3);
    left->addLeftChild(4);
    right->addRightChild(5);
    root->left=left;
    root->right=right;
    std::cout<<dfsForMaxWidth(root);
    return 0;
}