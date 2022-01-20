

#include"treeNode.h"
#include<deque>
#include<iostream>

int getSumWithDFS(TreeNode* root, int cur)
{
    if(!root)
        return 0;
    int sum=0;
    if(!root->left&&!root->right)
        return cur*10+root->m_val;
    if(root->left)
        sum+=getSumWithDFS(root->left,cur*10+root->m_val);
    if(root->right)
        sum+=getSumWithDFS(root->right,cur*10+root->m_val);
    return sum;
}


int getSumWithBFS(TreeNode* root)
{
    if(!root)
        return 0;
    int ans=0;

    std::deque<std::pair<TreeNode*,int>> d{};
    d.push_back(std::pair<TreeNode*,int>(root,root->m_val));

    while(!d.empty())
    {
        TreeNode* curNode=d.front().first;
        int curValue=d.front().second;
        d.pop_front();
        if(!curNode->left && !curNode->right)
            ans+=curValue;
        if(curNode->left)
            d.push_back(std::pair<TreeNode*,int>(curNode->left,curValue*10+curNode->left->m_val));
        
        if(curNode->right)
            d.push_back(std::pair<TreeNode*,int>(curNode->right,curValue*10+curNode->right->m_val));
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
    int res=getSumWithDFS(root,0);
    std::cout<<res<<'\n';
    return 0;
}