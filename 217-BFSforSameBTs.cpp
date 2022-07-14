#include"treeNode.h"
#include<deque>
#include<iostream>
#include<vector>

using DT=std::deque<std::vector<TreeNode*>>;

bool isSameBTs(TreeNode* s,TreeNode* t)
{
    DT q{};
    std::vector<TreeNode*> tmpVec{s,t};
    q.push_back(tmpVec);
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;++i)  //why add this for-loop? if needs to compare level by level,we should add this for loop?
        {
            TreeNode* n1=q.front()[0];
            TreeNode* n2=q.front()[1];
            q.pop_front();
            if(!n1&&!n2)
                continue;
            if(!n1||!n2)
                return false;
            if(n1->m_val!=n2->m_val)
                return false;
            std::vector<TreeNode*> left{n1->left,n2->left};
            q.push_back(left);
            std::vector<TreeNode*> right{n1->right,n2->right};
            q.push_back(right);
        }
    }
    return true;
}

int main()
{
    TreeNode* r1=new TreeNode(1);
    TreeNode* r2=new TreeNode(1);
    r1->addLeftChild(2);
    r2->addLeftChild(2);
    r1->addRightChild(3);
    r2->addRightChild(4);

    std::cout<<isSameBTs(r1,r2);
    return 0;
}