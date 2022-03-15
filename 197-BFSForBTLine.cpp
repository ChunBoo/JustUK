#include<iostream>
#include"treeNode.h"
#include<deque>
#include<cmath>
#include<set>
using DT=std::deque<std::pair<TreeNode*,int>>;
using PAIR=std::pair<TreeNode*,int>;
int getLinesBTSet(TreeNode* root)
{
    if(!root)
        return 0;
    DT q;
    q.push_back({root,0});
    std::set<int> data;
    while(!q.empty())
    {
        TreeNode* curNode=q.front().first;
        int offset=q.front().second;
        data.insert(offset);
        q.pop_front();
        if(curNode->left)
            q.push_back({root->left,offset-1});
        if(curNode->right)
            q.push_back({root->right,offset+1});
    }
    return data.size();
}



size_t getLinesBT(TreeNode* root)
{
    size_t ans=0;
    if(!root)
        return ans;
    std::deque<TreeNode*> q{};
    q.push_back(root);
    while(!q.empty())
    {
        ans=std::max(ans,q.size()+1);

        TreeNode* cur=q.front();
        q.pop_front();
        if(cur->left)
            q.push_back(cur->left);
        if(cur->right)
            q.push_back(cur->right);
    }
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(2);
    root->addLeftChild(1);
    root->addRightChild(3);
    std::cout<<getLinesBTSet(root);
    return 0;
}