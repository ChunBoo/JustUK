#include"../treeNode.h"
#include<deque>
#include<map>
#include<set>
#include<iostream>
#include<vector>

using MAP=std::map<int,std::vector<int>>;
using PAIR=std::pair<int,int>;
void dfs(TreeNode* root, TreeNode* par, MAP& G)
{
    if(!root)
        return ;

    if(par)
    {
        G[root->m_val].push_back(par->m_val);
        G[par->m_val].push_back(root->m_val);
    }
    dfs(root->left,root,G);
    dfs(root->right,root,G);
}

int bfs(int node,MAP& G)
{
    if(node&1)
        return 0;

    int ans=0;
    std::deque<PAIR> q{};
    q.push_back(PAIR(1,1));
    std::set<int> seen{};
    seen.insert(node);
    while(!q.empty())
    {
        PAIR cur=q.front();
        q.pop_front();
        ans=std::max(ans,cur.second);
        for(auto &v:G[cur.first])
        {
            if((seen.find(v)==seen.end()) && (v&1)==0)
            {
                seen.insert(v);
                q.push_back(PAIR(v,cur.second+1));
            }
        }
    }
    return ans;
}


int getLongestNodesCount(TreeNode* node)
{
    if(!node)
        return 0;
    
    int ans=0;
    MAP G{};
    dfs(node,nullptr,G);
    for(auto &[k,v]:G)
    {
        if((k&1)==0)
        {
            ans=std::max(ans,bfs(k,G));
        }
    }
    return ans;
}

int main()
{
TreeNode *root=new TreeNode(0);
TreeNode *left1=new TreeNode(8);
TreeNode *right1=new TreeNode(2);

TreeNode *rLeft2=new TreeNode(6);
TreeNode *rright2=new TreeNode(0);
TreeNode *rLeft3=new TreeNode(4);

root->left=left1;
root->right=right1;

right1->left=rLeft2;
right1->right=rright2;

rLeft2->left=rLeft3;

std::cout<<getLongestNodesCount(root);
}