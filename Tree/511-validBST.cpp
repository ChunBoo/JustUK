#include "../treeNode.h"
#include<iostream>
#include<stack>

using std::cout;
using PAIR=std::pair<const TreeNode*,std::pair<int,int>>;
using STACK=std::stack<PAIR>;


bool isValidBST(const TreeNode* root)
{
    if(!root)
        return true;

    STACK st{PAIR(root,std::pair<int,int>(INT_MIN,INT_MAX))};
    while(!st.empty())
    {
        PAIR top=st.top();
        st.pop();
        const TreeNode* curNode=top.first;
        int L=top.second.first;
        int R=top.second.second;

        if(curNode->m_val<=L || curNode->m_val>=R)
            return false;
        if(curNode->left)
            st.push(PAIR(curNode->left,std::pair<int,int>(L,curNode->m_val)));
        if(curNode->right)
            st.push(PAIR(curNode->right,std::pair<int,int>(curNode->m_val,R)));
    }
    return true;
}

int main()
{
    TreeNode* seven=new TreeNode(7);
    TreeNode* eight=new TreeNode(8);
    TreeNode* five=new TreeNode(5);
    TreeNode* four=new TreeNode(4);
    TreeNode* two=new TreeNode(2);
    TreeNode* one=new TreeNode(1);
    TreeNode* three=new TreeNode(3);

    seven->left=five;
    five->left=four;
    four->left=two;
    two->left=one;
    two->right=three;
    seven->right=eight;
    cout<<isValidBST(seven);
}
