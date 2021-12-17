//using  BFS to get max depth of a binary tree

#include "treeNode.h"
#include<deque>
#include<iostream>


int maxDepthByBFS(TreeNode* root)
{
    if(!root)
        return 0;
    
    std::deque<std::pair<TreeNode*,int>> d{std::pair<TreeNode*,int>(root,1)};
    int ans=0;
    while(!d.empty())
    {
        std::pair<TreeNode*,int> tempNode=d.front();
        d.pop_front();
        TreeNode* childNode=tempNode.first;
        int curDepth=tempNode.second;
        ans=std::max(ans,curDepth);

        if(childNode->left)
            d.push_back(std::pair<TreeNode*,int>(childNode->left,curDepth+1));

        if(childNode->right)
            d.push_back(std::pair<TreeNode*,int>(childNode->right,curDepth+1));
    }

    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(6);
    // root->addLeftChild(2);
    TreeNode*  left=new TreeNode(5);
    TreeNode* leftLeft=new TreeNode(4);
    leftLeft->addRightChild(3);
    left->left=leftLeft;
    root->left=left;

    int depth=maxDepthByBFS(root);
    std::cout<<"Max depth is: "<<depth<<'\n';

    return 0;   
}
