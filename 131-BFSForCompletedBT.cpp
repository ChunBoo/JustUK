#include"treeNode.h"
#include<iostream>
#include<deque>
#include<cmath>

bool isCompletedBT(TreeNode* root)
{
    if(!root)
        return true;

    std::deque<TreeNode*> nb;
    nb.push_back(root);

    bool Hole=false;

    while(!nb.empty())
    {
        TreeNode* curNode=nb.front();
        nb.pop_front();
        if(!curNode)
            Hole=true;
        else
        {
            if(Hole) return false;
            nb.push_back(curNode->left);
            nb.push_back(curNode->right);
        }
    }
    return true;
}


bool isCompletedBT2(TreeNode* root)
{
    if(!root)
        return true;

    std::deque<TreeNode*> nb{};
    nb.push_back(root);
    int level=0;
    int totalNodes=0;
    while(!nb.empty())
    {
        int sz=nb.size();
        for(int i=0;i<sz;++i)
        {
            TreeNode* curNode=nb.front();
            totalNodes+=1;
            nb.pop_front();
            if(curNode->left)
                nb.push_back(curNode->left);
            if(curNode->right)
                nb.push_back(curNode->right);
        }
        level+=1;
    }
    return totalNodes==std::pow(2,level)-1;
}

int main()
{
    TreeNode* root=new TreeNode(20);
    TreeNode* l1Left=new TreeNode(2);
    TreeNode* l1right=new TreeNode(3);
    TreeNode* l21left=new TreeNode(4);
    TreeNode* l21right=new TreeNode(5);
    TreeNode* l22left=new TreeNode(6);
    TreeNode* l22right=new TreeNode(7);
    
    l1Left->left=l21left;
    l1Left->right=l21right;
    
    l1right->left=l22left;
    l1right->right=l22right;

    root->left=l1Left;
    root->right=l1right; 

    bool res=isCompletedBT(root);
    std::cout<<res<<'\n';
    return 0;
}