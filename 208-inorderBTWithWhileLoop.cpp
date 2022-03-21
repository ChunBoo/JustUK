//while loop is iteration

#include<iostream>
#include<stack>

#include"treeNode.h"

#include<vector>

using DT=std::vector<int>;

DT inOrderBTWithIteration(TreeNode* root)
{
    std::stack<TreeNode*> s;
    DT ans{};
    if(!root)
        return ans;

    TreeNode* curNode=root;
    while(curNode ||!s.empty())
    {
        while(curNode)
        {
            s.push(curNode);
            curNode=curNode->left;
        }
        curNode=s.top();
        s.pop();
        ans.push_back(curNode->m_val);
        curNode=curNode->right;
    }
    return ans;
}

int main()
{
        TreeNode* root=new TreeNode(1);
    root->addLeftChild(2);
    root->addRightChild(3);
    DT res=inOrderBTWithIteration(root);
    for(auto i:res)
        std::cout<<i<<',';
    return 0;
}