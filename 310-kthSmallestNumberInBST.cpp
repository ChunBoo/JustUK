//given a binary search tree,return the kth smallest nodes value

#include"treeNode.h"
#include<stack>
#include<iostream>
#include<vector>
int kthSamllestNode_iterator(const TreeNode* root,int k)
{
    std::stack<const TreeNode*> s{};
    if(!root)
        return 0;
    
    const TreeNode* p=root;
    while(!s.empty() ||p)
    {
        if(p)
        {
            s.push(p);
            p=p->left;
        }
        else
        {
            p=s.top();
            s.pop();
            k-=1;
            if(!k)
                return p->m_val;
            p=p->right;
        }
    }
}



void dfs(const TreeNode* root,std::vector<int>& list)
{
    if(!root)
        return;
    dfs(root->left,list);
    list.push_back(root->m_val);
    dfs(root->right,list);
}

int kthSmallestNodes_dfs(const TreeNode* root,int k)
{
    if(!root)
        return 0;
    std::vector<int> data{};
    dfs(root,data);
    return data[k-1];
}


int main()
{
   TreeNode  *root=new TreeNode(5);
    TreeNode *left= new TreeNode(3);
    TreeNode *left2=new TreeNode(2);
    TreeNode *right2=new TreeNode(4);

    TreeNode *right=new TreeNode(7);
    TreeNode *rleft=new TreeNode(6);
    TreeNode *rright=new TreeNode(8);
    root->left=left;
    root->right=right;
    left->left=left2;
    left->right=right2;

    right->left=rleft;
    right->right=rright;
    std::cout<<kthSamllestNode_iterator(root,3);
    return 0;
}