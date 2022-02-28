//given a tree,return it is a sum BT or not
#include "treeNode.h"
#include<deque>
#include<iostream>

bool isSumBT(TreeNode* root)
{
    if(!root)
        return true;
    
    std::deque<TreeNode*> q;
    q.push_back(root);
    while(!q.empty())
    {
            int sum=0;
            TreeNode* curNode=q.front();
            q.pop_front();
            if(!curNode->left&&!curNode->right)
                continue;
            if(curNode->left)
            {
                sum+=curNode->left->m_val;
                q.push_back(curNode->left);
            }
            if(curNode->right)
            {
                sum+=curNode->right->m_val;
                q.push_back(curNode->right);
            }
            if(curNode->m_val!=sum)
                return false;
    }
    return true;
}

int main()
{
        TreeNode* r1=new TreeNode(7);
    TreeNode* l1=new TreeNode(3);
    TreeNode* r11=new TreeNode(2);
    r1->left=l1;
    r1->right=r11;
    std::cout<<isSumBT(r1)<<'\n';
    return 0;
}