#include"treeNode.h"
#include<iostream>


bool isSameOfTwoBTs(TreeNode* s,TreeNode* t)
{
    if(!s&&!t)
        return true;
    if(!s||!t)
        return false;
    if(s->m_val!=t->m_val)
        return false;

    return isSameOfTwoBTs(s->left,t->left) && isSameOfTwoBTs(s->right,t->right);
}

int main()
{
    TreeNode* r1=new TreeNode(1);
    TreeNode* r2=new TreeNode(1);
    r1->addLeftChild(2);
    r2->addLeftChild(2);
    r1->addRightChild(3);
    r2->addRightChild(3);

    std::cout<<isSameOfTwoBTs(r1,r2);
    return 0;
}