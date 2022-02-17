//dfs for getting the maximum value of subTree, NOTE: Empty tree also is a subtree

// #include"treeNode.h"
#include<iostream>
#include<cmath>
#if 0
int dfs(TreeNode* root,int& maxSum)
{
    if(!root)
        return 0;
    int x1=root->m_val+dfs(root->left,maxSum);
    int x2=root->m_val+dfs(root->right,maxSum);

    int x=std::max(x1,x2);   
    maxSum=std::max(x,maxSum);
    return x;
}

int maxSumOfSubTree(TreeNode* root)
{
    if(!root)
        return 0;
    int ans=0;
    dfs(root,ans);
    return ans<0?0:ans;

}




#endif

struct TreeNode  
{  
    int val;  
    TreeNode *left;  
    TreeNode *right;  
    TreeNode(int v):val{v},left{},right{}{}
};  
  
int visit(TreeNode *root, int &result)  
{  
    if (root == NULL)  
    {  
        return 0;  
    }  
  
    int sum = root->val;  
    if (root->left != NULL || root->right != NULL)  
    {  
        int left = visit(root->left, result);  
        int right = visit(root->right, result);  
        sum += left + right;  
  
        result = std::max(sum, result);  
    }  
  
    return sum;  
}  
  
int maxSum(TreeNode *root)  
{  
    int result = INT_MIN;  
    visit(root, result);  
  
    return result;  
}  

int main()
{
    TreeNode* root=new TreeNode(2);
    TreeNode* left=new TreeNode(1);
    TreeNode* right=new TreeNode(-4);
    root->left=left;
    root->right=right;
    int res=maxSum(root);
    std::cout<<res;
    return 0;
}