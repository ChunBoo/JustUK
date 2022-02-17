#include "treeNode.h"
#include<map>
#include<iostream>


int getLevelNumberWithMaximumSum(TreeNode* root,std::map<int,int>& nb,int curLevel)
{
    if(!root)
        return 0;
    int ans=0;
    int maxSum=0;
    nb[curLevel]+=root->m_val;
    if(root->left)
        getLevelNumberWithMaximumSum(root->left,nb,curLevel+1);
    if(root->right)
        getLevelNumberWithMaximumSum(root->right,nb,curLevel+1);
    for(auto level:nb)
    {
        if(maxSum<level.second)
        {
            maxSum=level.second;    
            ans=level.first;
        }
    }
    std::cout<<ans<<" With sum is: "<<maxSum<<'\n';
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(20);
    TreeNode* l1Left=new TreeNode(2);
    TreeNode* l1right=new TreeNode(3);
    TreeNode* l21left=new TreeNode(4);
    TreeNode* l21right=new TreeNode(5);
    TreeNode* l22left=new TreeNode(6);
    TreeNode* l22right=new TreeNode(7);
    
    l1Left->left=l21left;
    l1Left->right=l21right;
    
    l1right->left=l22left;
    l1right->right=l22right;

    root->left=l1Left;
    root->right=l1right; 
    std::map<int,int> nb{};

    int res=getLevelNumberWithMaximumSum(root,nb,0);
    std::cout<<res<<'\n';
    return 0;
}