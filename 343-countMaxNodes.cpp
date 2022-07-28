#include"treeNode.h"
#include<iostream>
#include<cmath>


int dfs_postorder(const TreeNode* root,int &res)
{
    if(!root)
        return 0;
    
    int left=dfs_postorder(root->left, res);
    int right=dfs_postorder(root->right,res);
    int tempMax=std::max(left,right);

    if(root->m_val>=tempMax)
        res++;
    return std::max(tempMax,root->m_val);
}

int countOfMaxNodes(const TreeNode* root)
{
    if(!root)
        return 0;
    int ans=0;
    dfs_postorder(root,ans);
    return ans;
}

/*
root=TreeNode(6)
left1=TreeNode(3)
right1=TreeNode(2)
left21=TreeNode(6)
right22=TreeNode(4)

*/
int main()
{
    TreeNode *root=new TreeNode(6);
    TreeNode *left= new TreeNode(3);
    TreeNode *right=new TreeNode(2);
    TreeNode *rightLeft=new TreeNode(6);
    TreeNode *rightright=new TreeNode(4);

    root->left=left;
    root->right=right;
    right->left=rightLeft;
    right->right=rightright;

    std::cout<<countOfMaxNodes(root);
    return 0;
}




