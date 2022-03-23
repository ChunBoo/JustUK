//while loop is iteration
//used std::stack to solve it
#include<iostream>
#include<stack>
#include"treeNode.h"
#include<vector>
using DT=std::vector<int>;

DT inOrderBTWithIteration(TreeNode* root)   
{
    DT ans{};
    if(!root)
        return ans;
    
    std::stack<TreeNode*> s{};
    TreeNode* curNode=root;
    while(curNode||!s.empty())
    {
        //findout the last left node
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