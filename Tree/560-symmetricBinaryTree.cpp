#include<iostream>
#include<deque>

class TreeNode
{
    public:
        int m_v{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode(int v,TreeNode* l=nullptr, TreeNode* r=nullptr):m_v{v},left{l},right{r}{};
};


bool isSymmetric(const TreeNode* root)
{
    std::deque<std::pair<const TreeNode*,const TreeNode*>> q{};
    q.push_back(std::make_pair(root,root));

    while(!q.empty())
    {
        std::pair<const TreeNode*,const TreeNode*> cur=q.front();
        q.pop_front();
        const TreeNode *a=cur.first,*b=cur.second;
        if((!a)&&(!b))
            continue;
        if((!a)||(!b))
            return false;
        if(a->m_v!=b->m_v)
            return false;
        
        q.push_back(std::make_pair(a->left,b->right));
        q.push_back(std::make_pair(a->right,b->left));
        
    }
    return true;
}

bool dfoo(const TreeNode* a, const TreeNode* b)
{
    if(!a&&!b)
        return true;
    if(!a || !b)
        return false;
    return (a->m_v==b->m_v)&&(dfoo(a->left,b->right))&&(dfoo(a->right,b->left)); 
}


bool isSymmetric2(const TreeNode* root)
{
    return dfoo(root,root);
}


int main()
{
    TreeNode *root=new TreeNode(10);
    TreeNode *one=new TreeNode(1);
    TreeNode *two=new TreeNode(2);
    TreeNode *two2=new TreeNode(2);
    TreeNode *third=new TreeNode(3);
    TreeNode *four=new TreeNode(4);

    root->left=two;
    root->right=two2;
    two->left=third;
    two->right=four;
    two2->left=four;
    two2->right=third;

    std::cout<<isSymmetric(root);
    std::cout<<isSymmetric2(root);
}