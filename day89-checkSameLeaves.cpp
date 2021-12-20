#include"treeNode.h"
#include<iostream>
#include<vector>
void getLeavesList(TreeNode* root,std::vector<int>& list)
{
    if(!root)
        return;
    
    if(!root->left&&!root->right)
        list.push_back(root->m_val);
    
    getLeavesList(root->left,list);
    getLeavesList(root->right,list);
}

bool isSameLeaves(TreeNode* rootA,TreeNode* rootB)
{
    if(!rootA||!rootB)
        return false;
    
    std::vector<int> la{};
    std::vector<int> lb{};
    getLeavesList(rootA,la);
    getLeavesList(rootB,lb);
    return la==lb;
}


int main()
{
    TreeNode* ra=new TreeNode(-1);
    ra->addLeftChild(2);
    ra->addRightChild(3);

    TreeNode* rb=new TreeNode(6);
    rb->addLeftChild(2);

    bool result=isSameLeaves(ra,rb);
    std::cout<<"result is:"<<result<<'\n';

    return 0;
}