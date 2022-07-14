#include"treeNode.h"
#include<iostream>


int main()
{
    TreeNode* r1=new TreeNode(1);
    TreeNode* r2=new TreeNode(1);
    r1->addLeftChild(2);
    r2->addLeftChild(2);
    r1->addRightChild(3);
    r2->addRightChild(5);

    std::cout<<isSameOfTwoBTs2(r1,r2);
    return 0;
}