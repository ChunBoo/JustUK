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

    STACK st{};
    st.push(PAIR(root,std::pair<int,int>(INT_MIN,INT_MAX)));
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

bool isValidBSTInorder(const TreeNode* root)
{
    std::stack<const TreeNode*> st{};
    int prev=INT_MIN;
    if(!root)
        return true;
    while(root ||!st.empty())
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        root=st.top();
        st.pop();
        if(root->m_val<=prev)
            return false;
        prev=root->m_val;
        root=root->right;
    }
    return true;
}
bool dfoo(const TreeNode* root,int& prev)
{
    if(!root)
        return true;
    if(!dfoo(root->left,prev))
        return false;
    if(root->m_val<=prev)
        return false;
    prev=root->m_val;
    dfoo(root->right,prev);
}
bool isValidBSTDfs(const TreeNode* root)
{
    int prev=INT_MIN;
    return dfoo(root,prev);
    
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
    // cout<<isValidBST(seven)<<'\n';
    // cout<<isValidBSTInorder(seven);
    cout<<isValidBSTDfs(seven);
}
