//given a BST,get the level which has maximum sum of each nodes

#include<iostream>
#include "treeNode.h"
#include<vector>
#include<map>

void getLevelNode(TreeNode* root,std::map<int,int>& nb,int curLevel)
{
    if(!root)
        return ;
    
    int curValue=root->m_val;
    nb[curLevel]+=(curValue);
    if(root->left)
        getLevelNode(root->left,nb,curLevel+1);
    if(root->right)
        getLevelNode(root->right,nb,curLevel+1);
    
}
int getLevel(TreeNode* root)
{
    int ans=0;
    if(!root)
        return ans;
    std::map<int,int> nb{};

    getLevelNode(root,nb,0);
    int maxSum=0;
    for(auto i:nb)
    {
        // int sum=0;
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

    int res=getLevel(root);
    std::cout<<res<<'\n';
    return 0;
}