//given a bt,binary tree,to get the nodes which just have only one child
//BFS method
#include "treeNode.h"
#include<iostream>
#include <deque>
#include<vector>

void getNodesCountWithOneChild(TreeNode* root)  //this method
{
    using PAIR_TYPE=std::pair<TreeNode*,int>;
    if(!root)
        return ;
    int ans=0;
    std::deque<std::pair<TreeNode*,int>> nb;
    nb.push_back(PAIR_TYPE(root,0));
    std::vector<TreeNode*> nodes;
    while(!nb.empty())
    {
        TreeNode* curNode=nb.front().first;
        int curCnt=nb.front().second;
        nb.pop_front();
        if(curCnt==1)
            // nodes.push_back(curNode);
            ans+=1;
        
        int x=0;
        if(curNode->left)
            x+=1;
        if(curNode->right)
            x+=1;
        if(curNode->left)
            nb.push_back(PAIR_TYPE(curNode->left,x));
        if(curNode->right)
            nb.push_back(PAIR_TYPE(curNode->right,x));
    }
    std::cout<<"Total count is:"<<ans<<'\n';
    // for(auto i:nodes)
    //     std::cout<<i->m_val<<'\n';
}

void getNodesWithOnlyOneChild(TreeNode* root)
{
    if(!root)
        return ;
    std::deque<TreeNode*> nb{};
    nb.push_back(root);
    int ans=0;
    std::vector<TreeNode*> nodes{};
    while(!nb.empty())
    {
        TreeNode* curNode=nb.front();
        nb.pop_front();
        
        // int x=0;
        if((curNode->left&&!curNode->right)||(curNode->right&&!curNode->left))
            nodes.push_back(curNode);
            // nb.push_back()
        if(curNode->left)
            nb.push_back(curNode->left);
        
        if(curNode->right)
            nb.push_back(curNode->right);
    }

    if(nodes.empty())
        std::cout<<"There is no nodes with only one child.\n";

    for(auto i:nodes)
        std::cout<<i->m_val<<'\n';
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
    l1right->right=l22right;

    root->left=l1Left;
    // root->right=l1right; 
    
    getNodesCountWithOneChild(root);

    return 0;
}