//given a target number,to judge if this value is two nodes sum which in two separated trees

#include"treeNode.h"
#include<iostream>


bool isSumOfTwoNodes(TreeNode* ra,TreeNode* rb,int target)
{
    if(!ra||!rb)
        return false;
    
    if(ra->m_val+rb->m_val==target)
        return true;
    
    if(ra->m_val+rb->m_val>target)
        return isSumOfTwoNodes(ra->left,rb,target)||isSumOfTwoNodes(ra,rb->left,target);
    else
        return isSumOfTwoNodes(ra->right,rb,target)||isSumOfTwoNodes(ra,rb->right,target);
}


int main()
{
    TreeNode* ra=new TreeNode(5);
    ra->addLeftChild(4);
    ra->addRightChild(6);

    TreeNode* rb=new TreeNode(8);
    rb->addLeftChild(7);
    rb->addRightChild(9);

    bool result=isSumOfTwoNodes(ra,rb,16);
    std::cout<<"Found two nodes sum is target? "<<result<<'\n';
    return 0;
}