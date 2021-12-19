//given two trees to check if they have same leaves

#include"treeNode.h"
#include<vector>
#include<iostream>

void getLeaves(TreeNode* root,std::vector<int>& leavesList)
{
    if(!root)
        return;
    if(!root->left && !root->right)
    {
        leavesList.push_back(root->m_val);
    }
    getLeaves(root->left,leavesList);
    getLeaves(root->right,leavesList);
}

bool isSameLeaves(TreeNode* a, TreeNode* b)
{
    std::vector<int> listA;
    std::vector<int> listB;

    getLeaves(a,listA);
    getLeaves(b,listB);

    return listA==listB;

}
int main()
{
    TreeNode* rootA=new TreeNode(-1);
    rootA->addLeftChild(1);
    // rootA->addRightChild(3);

    TreeNode* rootB=new TreeNode(5);
    rootB->addLeftChild(1);
    rootB->addRightChild(3);
    bool isSame=isSameLeaves(rootA,rootB);
    std::cout<<isSame<<"\n";
    return 0;
}