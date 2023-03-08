
#include<iostream>
class TreeNode
{
    public:
        int m_v{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode(int v,TreeNode* l=nullptr, TreeNode* r=nullptr):m_v{v},left{l},right{r}{}
};

int dfoo(TreeNode* root,int& ans)
{
    if(!root)
        return 0;
    int lf=dfoo(root->left,ans);
    int rf=dfoo(root->right,ans);
    if((lf+rf)==root->m_v)
    {
        ans+=1;
    }
    return lf+rf+root->m_v;
}

int equalToDescendants(TreeNode* root)
{
    int ans=0;
    dfoo(root,ans);
    return ans;
}

int main()
{
    TreeNode *root=new TreeNode(10);
    TreeNode *three=new TreeNode(3);
    TreeNode *four=new TreeNode(4);
    TreeNode *one=new TreeNode(1);
    TreeNode *two=new TreeNode(2);

    root->right=four;
    root->left=three;
    three->left=one;
    three->right=two;
    std::cout<<equalToDescendants(root);




    
}