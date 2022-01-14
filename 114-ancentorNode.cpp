//found two nodes common ancentor
#include "treeNode.h"
#include <iostream>

TreeNode* commonAncentor(TreeNode* root, TreeNode* nodeA,TreeNode* nodeB)
{
    if(!root)
        return nullptr;
    if(root->m_val==nodeA->m_val || root->m_val==nodeB->m_val)
    {
        return root;
    }
    TreeNode* left=commonAncentor(root->left,nodeA,nodeB);
    TreeNode* right=commonAncentor(root->right,nodeA,nodeB);

    if(!left)
        return right;
    if(!right)
        return left;
    return root;
}


int main()
{
    TreeNode* root=new TreeNode(10);
    TreeNode* leftRoot=new TreeNode(88);
    TreeNode* lleftRoot=new TreeNode(3);
    TreeNode* lrightRoot=new TreeNode(7);
    TreeNode* lrlRoot=new TreeNode(6);

    root->left=leftRoot;
    leftRoot->left=lleftRoot;
    leftRoot->right=lrightRoot;
    lrightRoot->left=lrlRoot;
    TreeNode* res=commonAncentor(root,lleftRoot,lrlRoot);

    std::cout<<res->m_val<<'\n';

    return 0;
}