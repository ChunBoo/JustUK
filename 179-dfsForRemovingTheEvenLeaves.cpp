//dfs for removing the leaves which value is even
#include"treeNode.h"
#include<iostream>

TreeNode* deleteLeavesWithEvenValue(TreeNode* root)
{
    if(!root)
        return nullptr;
    if(root->left)
        root->left=deleteLeavesWithEvenValue(root->left);
    if(root->right)
        root->right=deleteLeavesWithEvenValue(root->right);
    if(!root->left&&!root->right)
    {
        if(root->m_val%2==0) //even value
            return nullptr;   //return nullptr to root.left or root.right,means delete this node
    }
    return root;
}

int main()
{
    TreeNode* r1=new TreeNode(6);
    TreeNode* l1=new TreeNode(4);
    TreeNode* r11=new TreeNode(2);
    r1->left=l1;
    r1->right=r11;
    r1->printTreeInOrder(r1);
    std::cout<<'\n';
    TreeNode* r2=deleteLeavesWithEvenValue(r1);
    r2->printTreeInOrder(r2);
    return 0;
}