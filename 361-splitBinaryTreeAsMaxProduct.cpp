#include"treeNode.h"
#include<iostream>
/*
Given a binary tree root, consider deleting an edge in the tree so that the tree becomes disjoint with two trees.
 Then, take the sum of each subtree and multiply the two numbers. 
 Return the largest such product we can get after deleting one edge.

Given the root of a binary tree, split the binary tree into two subtrees by removing 

one edge such that the product of the sums of the subtrees is maximized. 
Return the maximum product of the sums of the two subtrees.*/

int sumOfTree(TreeNode* root)
{
    if(!root)
        return 0;
    return root->m_val+sumOfTree(root->left)+sumOfTree(root->right);
}

int dfs(TreeNode* root,int sum,int &ans)
{
    if(!root)
        return 0;

    int cur=dfs(root->left,sum,ans)+dfs(root->right,sum,ans)+root->m_val;
    ans=std::max(cur*(sum-cur),ans);
    return cur;
}


int maxProductOfSubtrees(TreeNode* root)
{
    int ans=INT_MIN;
    int sum=sumOfTree(root);
    dfs(root,sum,ans);
    return ans;
}


int main()
{
    // root=TreeNode(1)
    TreeNode *root=new TreeNode(1);
    TreeNode *L1=new TreeNode(2);
    TreeNode *R1=new TreeNode(3);
    TreeNode *LL2=new TreeNode(4);
    TreeNode *LR2=new TreeNode(5);
    TreeNode *RL2=new TreeNode(6);

    root->left=L1;
    root->right=R1;
    
    L1->left=LL2;
    L1->right=LR2;
    R1->left=RL2;

    std::cout<<maxProductOfSubtrees(root);
    return 0;
}