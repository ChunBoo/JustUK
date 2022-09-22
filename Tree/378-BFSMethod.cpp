#include<iostream>
#include"../treeNode.h"

#include<deque>
#include<map>
#include<set>
#include<vector>
using MAP=std::map<TreeNode*,std::vector<TreeNode*>>;
using PAIR=std::pair<TreeNode*,int>;
//covert the binary tree to graph(adjacent list)
void dfs(TreeNode* root,TreeNode* par,MAP& G)
{
    if(!root)
        return ;

    if(par)
    {
        G[par].push_back(root);
        G[root].push_back(par);
    }
    dfs(root->left,root,G);
    dfs(root->right,root,G);   
}

int bfs(TreeNode* node,MAP& G)
{
    int ans=0;
    std::set<TreeNode*> seen{};
    seen.insert(node);
    std::deque<PAIR> q{};
    q.push_back(PAIR(node,1));

    while(!q.empty())
    {
        PAIR cur=q.front();
        q.pop_front();
        ans=std::max(ans,cur.second);
        for(auto v:G[cur.first])
        {
            if((seen.find(v)==seen.end())&&((v->m_val&1)==0))  //opreator & is lower than ==
            {
                seen.insert(v);
                q.push_back(PAIR(v,cur.second+1));
            }
        }
    }
    return ans;
}

int getLongestEvenPathNodesCount(TreeNode* root)
{
    if(!root)
        return 0;
    
    int ans=0;
    MAP G{};
    dfs(root,nullptr,G);
    for(auto &[k,v]:G)
    {
        ans=std::max(ans,bfs(k,G));
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

std::cout<<getLongestEvenPathNodesCount(root);
}