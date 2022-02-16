#include"treeNode.h"
#include<deque>
#include<iostream>
#include<vector>


using PAIR_TYPE=std::pair<TreeNode*,int>;
void getNodesWithOneChild(TreeNode* root)
{
    if(!root)
        return ;
    
    std::deque<PAIR_TYPE> nb{};

    nb.push_back(PAIR_TYPE(root,0));
    int ans=0;
    while(!nb.empty())
    {
        TreeNode* curNode=nb.front().first;
        int curCnt=nb.front().second;
        nb.pop_front();
        if(curCnt==1)
           ans+=1;
        int x=0;
        if(curNode->left)
            x+=1;
        if(curNode->right)
            x+=1;
        if(curNode->left)
            nb.push_back(PAIR_TYPE(curNode->left,x));
        if(curNode->right)
            nb.push_back(PAIR_TYPE(curNode->right,x));

    }
    std::cout<<ans<<'\n';

}

void getChildNode(TreeNode* root)
{
    if(!root)
        return;
    std::deque<TreeNode*> nb{};
    nb.push_back(root);

    while(!nb.empty())
    {
        TreeNode* curNode=nb.front();
        nb.pop_front();
        if((curNode->left&&!curNode->right)||(curNode->right&&!curNode->left))
            std::cout<<curNode->m_val<<',';
        if(curNode->left)
            nb.push_back(curNode->left);
        if(curNode->right)
            nb.push_back(curNode->right);
    }
}

int main()
{
    TreeNode* root=new TreeNode(20);
    TreeNode* l1Left=new TreeNode(2);
    TreeNode* l1right=new TreeNode(3);
    TreeNode* l21left=new TreeNode(4);
    TreeNode* l21right=new TreeNode(5);
    TreeNode* l22left=new TreeNode(6);
    TreeNode* l22right=new TreeNode(7);
    
    l1Left->left=l21left;
    // l1Left->right=l21right;
    
    l1right->left=l22left;
    // l1right->right=l22right;

    root->left=l1Left;
    root->right=l1right;

    getNodesWithOneChild(root);
    return 0;
}