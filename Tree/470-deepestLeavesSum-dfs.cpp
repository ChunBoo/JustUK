#include<iostream>
#include<map>

using MAP=std::map<int,int>; //key:lvl,value:sum

class TreeNode
{
    public:
        int m_val{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode(int v,TreeNode* l=nullptr,TreeNode* r=nullptr):m_val{v},left{l},right{r}{};
};

void foo(MAP& d,const TreeNode* root,int lvl)
{
    if(!root)
        return ;

    d[lvl]+=root->m_val;
    if(root->left)
        foo(d,root->left,lvl+1);
    if(root->right)
        foo(d,root->right,lvl+1);
}

int deepestLeaveSum(const TreeNode* root)
{
    if(!root)
        return 0;
    MAP d{};
    foo(d,root,0);
    int last=d.size()-1;
    return d[last];
}
//Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]

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