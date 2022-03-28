#include"treeNode.h"
#include<deque>
#include<iostream>
#include<vector>

using DT=std::deque<std::vector<TreeNode*>>;

bool isSameBTs(TreeNode* s,TreeNode* t)
{

    std::vector<TreeNode*> tmp{s,t};
    // DT q{std::vector<TreeNode*>(s,t)};
    DT q{};
    q.push_back(tmp);
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;++i)
        {
            TreeNode* t1=q.front()[0];
            TreeNode* t2=q.front()[1];
            q.pop_front();
            if(!t1&&!t2)
                // return true;  //can not return true here,as there are other nodes not checked
                continue;
            if(!t1||!t2)
                return false;
            if(t1->m_val!=t2->m_val)
                return false;
            std::vector<TreeNode*> tmp{t1->left,t2->left};
            q.push_back(tmp);
            std::vector<TreeNode*> tmp2{t1->right,t2->right};

            q.push_back(tmp2);
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