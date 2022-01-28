#include"treeNode.h"
#include<deque>
#include<iostream>
#include<vector>
void getChildNode(TreeNode* root)
{
    if(!root)
        return ;
    std::vector<TreeNode*> nodes;
    std::deque<TreeNode*> nb;
    nb.push_back(root);
    while(!nb.empty())
    {
        TreeNode* curNode=nb.front();
        
        nb.pop_front();
        if((curNode->left && !curNode->right)||(curNode->right&&!curNode->left))
            nodes.push_back(curNode);

        if(curNode->left)
            nb.push_back(curNode->left);
        if(curNode->right)
            nb.push_back(curNode->right);   
    }
    for(auto n:nodes)
    {
        std::cout<<n->m_val<<",";
    }
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
    // l1Left->right=l21right;
    
    l1right->left=l22left;
    // l1right->right=l22right;

    // root->left=l1Left;
    root->right=l1right;

    getChildNode(root);
    return 0;
}