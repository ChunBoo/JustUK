#include<iostream>

class TreeNode
{
    public:
        int m_val{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode(int v,TreeNode* l=nullptr,TreeNode* r=nullptr):m_val{v},left{l},right{r}{};
};



TreeNode* foo(TreeNode* a,TreeNode* b, TreeNode* target)
{
    if(!a)
        return nullptr;
    if(a->m_val==target->m_val)
        return b;
    foo(a->left,b->left,target);
    foo(a->right,b->right,target);
}

TreeNode* getTargetCopy(TreeNode* a,TreeNode* b, TreeNode* target)
{
    return foo(a,b,target);
}

