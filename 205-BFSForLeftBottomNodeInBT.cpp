//given a BT,return the left-bottom node

#include"treeNode.h"
#include<deque>
#include<iostream>

using DT=std::deque<TreeNode*>;
TreeNode* getLeftBottomNodeInBT(TreeNode* root)
{
    if(!root)
        return nullptr;

    DT q{};
    q.push_back(root);
    TreeNode* ans=nullptr;
    while(!q.empty())
    {
        int sz=q.size();

        ans=q.front();
        // q.pop_front();
        for(int i=0;i<sz;++i)
        {
            TreeNode* curNode=q.front();
            q.pop_front();
        if(curNode->left)
            q.push_back(curNode->left);
        if(curNode->right)
            q.push_back(curNode->right);
        }
    }
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(2);
    TreeNode* left=new TreeNode(1);
    left->addLeftChild(99);
    left->addRightChild(88);
    root->addRightChild(3);
    root->left=left;
    std::cout<<getLeftBottomNodeInBT(root)->m_val;
    return 0;
}