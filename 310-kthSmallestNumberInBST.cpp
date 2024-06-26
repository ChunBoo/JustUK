//given a binary search tree,return the kth smallest nodes value
//solution:use the dfs or iterator to get all the nodes of binary search tree

#include"treeNode.h"
#include<stack>
#include<iostream>
#include<vector>
int kthSamllestNode_iterator(const TreeNode* root,int k)  //will use the std::stack 
{
    if(!root)
        return 0 ;

    std::stack<const TreeNode*> s{};
    const TreeNode* p=root;
    while(!s.empty()||p)
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

            if(k==0)
                return p->m_val;
            p=p->right;
        }
    }
}



void dfs(const TreeNode* root,std::vector<int>& list)
{
    if(!root)
        return;
    // if(root->left)
        dfs(root->left,list);
    list.push_back(root->m_val);
    // if(root->right)
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
    std::cout<<kthSmallestNodes_dfs(root,3);
    return 0;
}