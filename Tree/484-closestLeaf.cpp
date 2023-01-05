#include<map>
#include<iostream>
#include<set>
#include<deque>
#include<vector>

using VEC=std::vector<int>;
using MAP=std::map<int,VEC>;
using Q=std::deque<int>;
using SET=std::set<int>;
class TreeNode
{
    public:
        int m_val{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode(int v=0,TreeNode* l=nullptr,TreeNode* r=nullptr):m_val{v},left{l},right{r}{};
};

void foo(const TreeNode* root, const TreeNode* par,MAP& m,SET& s)
{
    if(!root)
        return ;
    foo(root->left,root,m,s);
    foo(root->right,root,m,s);
    if(par)  //double direction 
    {
        m[par->m_val].push_back(root->m_val);
        m[root->m_val].push_back(par->m_val);
    }
    if(!(root->left) &&!(root->right))
        s.insert(root->m_val);
}

int getCloestLeaf(const TreeNode* root,int k)
{
    //create the Graph for the BT
    MAP G{};
    SET leaves{};
    foo(root,nullptr,G,leaves);

    Q q{k};  //for BFS to get the shortest leaf from given target k
    // q.push_back(k);
    SET seen{};
    while(!q.empty())
    {
        int cur=q.front();
        q.pop_front();
        // auto search=leaves.find(cur);
        if(leaves.find(cur)!=leaves.end())
            return cur;
        for(auto &n:G[cur])
        {
            // auto isAlreadyAccessed=seen.find(n);
            if(seen.find(n)==seen.end())
            {
                seen.insert(n);
                q.push_back(n);
            }
        }
    }
}


int main()
{
    TreeNode* root=new TreeNode();
    TreeNode* one=new TreeNode(1);
    TreeNode* two=new TreeNode(2);
    TreeNode* three=new TreeNode(3);
    TreeNode* four=new TreeNode(4);

    root->left=one;
    root->right=two;
    one->left=three;
    two->right=four;

    int leaf=getCloestLeaf(root,1);
    std::cout<<leaf;

}