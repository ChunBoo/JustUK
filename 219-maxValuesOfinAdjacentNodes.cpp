#include<iostream>
#include"treeNode.h"
#include<algorithm>  // can support the list of numbers
int maxSumOfInadjacentNodes(TreeNode* root,bool toTake)  //recursion method
{
    if(!root)
        return 0;
    int sum=0,val=0;
    if(toTake)
        val=root->m_val+maxSumOfInadjacentNodes(root->left,false)+maxSumOfInadjacentNodes(root->right,false);
    else
        val=std::max({maxSumOfInadjacentNodes(root->left,true)+maxSumOfInadjacentNodes(root->right,true),\
                     maxSumOfInadjacentNodes(root->left,true)+maxSumOfInadjacentNodes(root->right,false),\
                     maxSumOfInadjacentNodes(root->left,false)+maxSumOfInadjacentNodes(root->right,true),\
                     maxSumOfInadjacentNodes(root->left,false)+maxSumOfInadjacentNodes(root->right,false)});
    return val;
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
    int val=std::max(maxSumOfInadjacentNodes(root,true),maxSumOfInadjacentNodes(root,false));
    std::cout<<val;
    return 0;
}