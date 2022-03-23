#include"treeNode.h"
#include<deque>
#include<iostream>
#include<cmath>
using DT=std::deque<std::pair<TreeNode*,int>>;
using PAIR=std::pair<TreeNode*,int>;
int maxWidthWithBFS(TreeNode* root)
{
    int ans=0;
    if(!root)
        return ans;

    DT q{PAIR(root,0)};
    while(!q.empty())
    {
        int sz=q.size();
        int L=INT_MAX,R=INT_MIN;
        for(int i=0;i<sz;++i)
        {
            TreeNode* curNode=q.front().first;
            int curVal=q.front().second;
            q.pop_front();
            L=std::min(L,curVal);
            R=std::max(R,curVal);
            if(curNode->left)
                q.push_back(PAIR(curNode->left,curVal*2));
            if(curNode->right)
                q.push_back(PAIR(curNode->right,curVal*2+1));
        }
        ans=std::max(ans,R-L+1);
    }
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* left=new TreeNode(2);
    TreeNode* right=new TreeNode(3);
    left->addLeftChild(4);
    right->addLeftChild(5);
    root->left=left;
    root->right=right;
    std::cout<<maxWidthWithBFS(root);
    return 0;
}