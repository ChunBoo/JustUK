#include<iostream>
#include<vector>

using VEC=std::vector<int>;

class TreeNode
{
    public:
        int val{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode(int v,TreeNode* l=nullptr, TreeNode* r=nullptr):val{v},left{l},right{r}{}
};


VEC dfs(TreeNode* root,int& ans)
{
    if(!root)
        return {0,0};
    VEC l{dfs(root->left,ans)};
    VEC r{dfs(root->right,ans)};
    int cnt=l[0]+r[0]+1,sum=root->val+l[1]+r[1];
    int average=sum/cnt;
    if(root->val==average)
        ans+=1;
    return {cnt,sum};
}



int countOfAverageOfSubTree( TreeNode* root)
{
    int ans=0;
    if(!root)
        return ans;
    int cnt=0,sum=0;
    dfs(root,ans);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(4);
    TreeNode* eight=new TreeNode(8);
    TreeNode* five=new TreeNode(5);
    TreeNode* zero=new TreeNode(0);
    TreeNode* one=new TreeNode(1);
    TreeNode* six=new TreeNode(6);
    root->left=eight;
    root->right=five;
    eight->left=zero;
    eight->right=one;
    five->right=six;

    std::cout<<countOfAverageOfSubTree(root);
}