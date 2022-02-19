#include "treeNode.h"
#include<iostream>
#include<stack>

int sumOfRange2(TreeNode* root,int L,int R)
{
    if(!root)
        return 0;
    std::stack<TreeNode*> s;
    s.push(root);
    int ans=0;
    while(!s.empty())
    {
        TreeNode* cur=s.top();
        s.pop();
        if(cur)
        {
            if(cur->m_val>=L && cur->m_val<=R)
            {
                ans+=cur->m_val;
            }
            if(cur->m_val>L)
                s.push(cur->left);
            if(cur->m_val<R)
                s.push(cur->right);
        }
    }
    return ans;
}


int sumOfRange(TreeNode* root, int L,int R)  //recursion version
{
    if(!root)
        return 0;
    
    int ans=0;
    if(root->m_val>=L && root->m_val<=R)
        ans+=root->m_val;

    if(root->m_val>L)   //here is no equal maker
        ans+=sumOfRange(root->left,L,R);

    if(root->m_val<R)
        ans+=sumOfRange(root->right,L,R);
    
    return ans;
}

int main()
{
    TreeNode* root= new TreeNode(1);
    TreeNode* right1= new TreeNode(3);
    TreeNode* left21= new TreeNode(2);
    TreeNode* right22= new TreeNode(6);
    right1->left=left21;
    right1->right=right22;
    root->addLeftChild(0);
    root->right=(right1);
    int res=sumOfRange2(root,2,9);
    std::cout<<res<<'\n';
    return 0;
}