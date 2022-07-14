//given a binary tree convert it to undirectional graph

#include "treeNode.h"
#include<queue> //for bfs
#include<iostream>
#include<map>  //for Graph {"vertex":[nodes]}  adjacent list
#include<vector>
using PAIR=std::pair<const TreeNode*,const TreeNode*>;

using DT=std::map<int,std::vector<int>>;

DT convertBT2UndirectionalGraph_BFS(const TreeNode* root)
{
    DT ans{};
    if(!root)
        return ans;

    std::queue<PAIR> q;
    q.push(PAIR(root,nullptr));

    while(!q.empty())
    {
        const TreeNode* cur=q.front().first;
        const TreeNode* parent=q.front().second;
        q.pop();

        if(!cur)
            continue;
        if(parent)
        {
            ans[cur->m_val].push_back(parent->m_val);
            ans[parent->m_val].push_back(cur->m_val);
        }
        q.push(PAIR(cur->left,cur));
        q.push(PAIR(cur->right,cur));
    }
    return ans;
}



void dfs(DT& ans,const TreeNode* root, const TreeNode* parent)
{
    if(!root)
        return ;
    if(parent)
    {
        ans[root->m_val].push_back(parent->m_val);
        ans[parent->m_val].push_back(root->m_val);
    }
    dfs(ans,root->left,root);
    dfs(ans,root->right,root);
}
DT convertBT2UndirectionalGraph_DFS(const TreeNode* root)
{
    DT ans{};
    if(!root)
        return ans;

    dfs(ans,root,nullptr);
}


int main()
{
    TreeNode *root=new TreeNode(5);
    TreeNode *left=new TreeNode(3);
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

    DT res1=convertBT2UndirectionalGraph_DFS(root);
    DT res=convertBT2UndirectionalGraph_BFS(root);

    std::map<int,std::vector<int>>::iterator iter=res.begin();
    for(;iter!=res.end();++iter)
    {
        std::cout<<iter->first<<"-->";
        for(auto &v:iter->second)
            std::cout<<v<<',';
        std::cout<<'\n';

    }
}

