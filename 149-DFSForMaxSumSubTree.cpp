//dfs for getting the maximum value of subTree, NOTE: Empty tree also is a subtree

#include"treeNode.h"
#include<iostream>
#include<cmath>

int dfs(TreeNode* root,int& maxSum)
{
    if(!root)
        return 0;
    int x1=root->m_val+dfs(root->left,maxSum);
    int x2=root->m_val+dfs(root->right,maxSum);

    int x=std::max(x1,x2);   
    maxSum=std::max(x,maxSum);
    return x;
}

int maxSumOfSubTree(TreeNode* root)
{
    if(!root)
        return 0;
    int ans=0;
    dfs(root,ans);
    return ans<0?0:ans;

}

int main()
{
    TreeNode* root=new TreeNode(2);
    root->addLeftChild(-1);
    root->addRightChild(-3);
    int res=maxSumOfSubTree(root);
    std::cout<<res;
    return 0;
}