#include<iostream>
#include<queue>

class TreeNode
{
    public:
        int m_val{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode(int v,TreeNode* l=nullptr,TreeNode* r=nullptr):m_val{v},left{l},right{r}{};
};

using Q=std::queue<const TreeNode*>;

int deepestLeaveSum(const TreeNode* root)
{
    if(!root)
        return 0;
    
    Q q{};
    q.push(root);
    int ans=0;
    while(!q.empty())
    {
        ans=0;
        int sz=q.size();
        for(int i=0;i<sz;++i)
        {
            const TreeNode* cur=q.front();
            q.pop();
            ans+=cur->m_val;
            if(cur->left)   
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
    return ans;
}

int main()
{
    TreeNode *root=new TreeNode(1);
    TreeNode *l2=new TreeNode(2);
    TreeNode *r3=new TreeNode(3);
    TreeNode *l4=new TreeNode(4);
    TreeNode *r5=new TreeNode(5);
    TreeNode *r6=new TreeNode(6);
    TreeNode *l7=new TreeNode(7);
    TreeNode *r8=new TreeNode(8);

    root->left=l2;
    root->right=r3;
    l2->left=l4;
    l2->right=r5;

    r3->right=r6;
    l4->left=l7;
    r6->right=r8;
    std::cout<<deepestLeaveSum(root);
}