#include "treeNode.h"
#include<deque>
#include<iostream>

int getSumWithDFS(TreeNode* root,int cur)
{
    if(!root)
        return ;
    int ans=0;

    if(!root->left && !root->right)
        return cur*10+root->m_val;
    
    if(root->left)
        ans+=getSumWithDFS(root->left,cur*10+root->left->m_val);
    
    if(root->right)
        ans+=getSumWithDFS(root->right,cur*10+root->right->m_val);
    
    return ans;
    
}



int getSumWithBFS(TreeNode* root)
{
    if(!root)
        return 0;
    
    int ans=0;
    std::deque<std::pair<TreeNode*,int>> q{std::pair<TreeNode*,int>(root,root->m_val)};

    while(!q.empty())
    {
        TreeNode* curNode=q.front().first;
        int curVal=q.front().second;
        q.pop_front();
        if(!curNode->left &&!curNode->right)
            ans+=curVal;
        
        if(curNode->left)
            q.push_back(std::pair<TreeNode*,int>(curNode->left,curVal*10+curNode->left->m_val));

        if(curNode->right)
            q.push_back(std::pair<TreeNode*,int>(curNode->right,curVal*10+curNode->right->m_val));
    }
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* left=new TreeNode(2);
    left->addLeftChild(4);
    root->left=left;
    root->addRightChild(3);
    // int res=getSumWithBFS(root);
    int res=getSumWithDFS(root,0);
    std::cout<<res<<'\n';
    return 0;
}
