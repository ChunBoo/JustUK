#include<set>
#include<iostream>
#include"treeNode.h"


int dfs(TreeNode* root,std::set<int>& s)
{
    if(!root)
        return 0;
    
    int left=dfs(root->left,s);
    int right=dfs(root->right,s);
    s.insert(left);
    s.insert(right);

    int t=left+right+root->m_val;
    s.insert(t);
    return t;
}

int sumOfTree(TreeNode* root)
{
    if(!root)
        return 0;

    return root->m_val+sumOfTree(root->left)+sumOfTree(root->right);
}
int maxProduct(TreeNode* root)
{
    std::set<int> sum{};

    if(!root)
        return 0;

    dfs(root,sum);
    int S=sumOfTree(root),ans=INT_MIN;
    for(auto &v: sum)
    {
        ans=std::max(ans,v*(S-v));
    }
    return ans;
}

int main()
{
        TreeNode *root=new TreeNode(1);
    TreeNode *L1=new TreeNode(2);
    TreeNode *R1=new TreeNode(3);
    TreeNode *LL2=new TreeNode(4);
    TreeNode *LR2=new TreeNode(5);
    TreeNode *RL2=new TreeNode(6);

    root->left=L1;
    root->right=R1;
    
    L1->left=LL2;
    L1->right=LR2;
    R1->left=RL2;

    std::cout<<maxProduct(root);
    return 0;
}