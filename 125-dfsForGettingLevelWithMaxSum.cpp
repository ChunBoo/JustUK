#include "treeNode.h"
#include<map>
#include<iostream>


int getLevelValue(TreeNode* root,std::map<int,int>& nb,int curLevel)
{
    if(!root)
        return 0;
    
    nb[curLevel]+=root->m_val;
    if(root->left)
        getLevelValue(root->left,nb,curLevel+1);
    if(root->right)
        getLevelValue(root->right,nb,curLevel+1);
    
    int ans=0;
    int maxSum=0;
    for(auto i:nb)
    {
        if(maxSum<i.second)
        {
            maxSum=i.second;
            ans=i.first;
        }
    }
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

    int res=getLevelValue(root,nb,0);
    std::cout<<res<<'\n';
    return 0;
}