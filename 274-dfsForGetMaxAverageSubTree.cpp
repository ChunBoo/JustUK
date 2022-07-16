//given a Binary tree,return the subtree which it is the maximum average

#include"treeNode.h"
#include<iostream>
#include<cmath>
using DT=std::pair<int,int>;

DT dfs(TreeNode* root,int& maxVal)
{
    if(!root)
        return DT(0,0);
    int sumLeft=dfs(root->left,maxVal).first;
    int countLeft=dfs(root->left,maxVal).second;

    int sumRight=dfs(root->right,maxVal).first;
    int countRight=dfs(root->right,maxVal).second;

    int S=sumLeft+sumRight+root->m_val;
    int C=countLeft+countRight+1;
    maxVal=std::max(S/C,maxVal);
    return DT(S,C);
}


int main()
{
    TreeNode* root=new TreeNode(3);
    root->addLeftChild(5);
    root->addRightChild(6);
    int max=-1;
    dfs(root,max);
    std::cout<<max<<'\n';
    return 0;
}