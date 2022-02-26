#include<iostream>
#include"treeNode.h"
#include<vector>

void dfs(TreeNode* root,std::vector<TreeNode*>& ans)
{
    if(!root)
        return ;

    if(!root->left&&!root->right)
        ans.push_back(root);
    
    dfs(root->left,ans);
    dfs(root->right,ans);
}

int isSimilarLeaves(TreeNode* r1,TreeNode* r2)
{
    std::vector<TreeNode*> list1;
    std::vector<TreeNode*> list2;
    dfs(r1,list1);
    dfs(r2,list2);

    int sz=list1.size();
    if(list1.size()!=list2.size())
        return false;
    for(int i=0;i<sz;++i)
    {
        if(list1[i]->m_val!=list2[i]->m_val)
            return false;
    }
    return true;
}


int main()
{
    TreeNode* r1=new TreeNode(2);
    TreeNode* l1=new TreeNode(3);
    TreeNode* r11=new TreeNode(4);
    r1->left=l1;
    r1->right=r11;

    TreeNode* r2=new TreeNode(2);
    TreeNode* l2=new TreeNode(3);
    TreeNode* r22=new TreeNode(4);
    r2->left=l2;
    r2->right=r22;
    std::cout<<isSimilarLeaves(r1,r2);
    return 0;
}
