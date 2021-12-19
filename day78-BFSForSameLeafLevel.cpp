//BFS for same leaf level

#include "treeNode.h"
#include<set>
#include<queue>
#include<iostream>
#include<map>

bool isSameLeafLevel(TreeNode* root)
{
    if(!root)
        return true;
    
    std::set<int> d{};
    std::queue<std::pair<TreeNode*,int>> q;

    q.push(std::pair<TreeNode*,int>(root,0));

    while(q.size())
    {
        std::pair<TreeNode*,int> tempNode=q.front();
        q.pop();
        if(!tempNode.first->left && !tempNode.first->right)
        {
            d.insert(tempNode.second);
            if(d.size()>1)
                return false;
        }
        if(tempNode.first->left)
            q.push(std::pair<TreeNode*,int>(tempNode.first->left,tempNode.second+1));
        if(tempNode.first->right)
            q.push(std::pair<TreeNode*,int>(tempNode.first->right,tempNode.second+1));
    }
    return true;
}

int main()
{
        TreeNode* root=new TreeNode(4);
    TreeNode* left=new TreeNode(3);
    // left->addLeftChild(2);
    root->left=left;
    TreeNode* right=new TreeNode(5);
    root->right=right;
    root->printTreeInOrder(root);
    std::cout<<'\n';

    bool sameLevel= isSameLeafLevel(root);
    std::cout<<sameLevel<<'\n';

    return 0;
}