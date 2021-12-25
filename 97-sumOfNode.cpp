#include"treeNode.h"
#include<iostream>

bool isSumOfNode(TreeNode* ra,TreeNode* rb,int target)
{
    if(!ra||!rb)
        return false;
    
    if(ra->m_val+rb->m_val==target)
        return true;
    if(ra->m_val+rb->m_val>target)
        return isSumOfNode(ra->left,rb,target)||isSumOfNode(ra,rb->left,target);
    
    if(ra->m_val+rb->m_val<target)
        return isSumOfNode(ra->right,rb,target)||isSumOfNode(ra,rb->right,target);
}


int main()
{
    TreeNode* ra=new TreeNode(4);
    TreeNode* rb=new TreeNode(6);
    ra->addLeftChild(2);
    ra->addRightChild(5);
    rb->addLeftChild(5);
    rb->addRightChild(7);

    int target=12;
    std::cout<<isSumOfNode(ra,rb,target)<<'\n';

    return 0;
}