//DFS way

#include "treeNode.h"
#include<iostream>
#include<vector>

int getCountOfNodesWithOneChild(TreeNode* root,std::vector<TreeNode*>& nodes)
{
    if(!root)
        return 0;
    int ans=0;
    if((root->left&&!root->right)||(root->right&&!root->left))
    {
        ans+=1;
        nodes.push_back(root);
    }
    if(root->left)
        ans+=getCountOfNodesWithOneChild(root->left,nodes);
    if(root->right)
        ans+=getCountOfNodesWithOneChild(root->right,nodes);
    
    return ans;
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
    
    // l1right->left=l22left;
    l1right->right=l22right;

    root->left=l1Left;
        root->right=l1right; 
    std::vector<TreeNode*> nodes{};
    int res=getCountOfNodesWithOneChild(root,nodes);
    std::cout<<res<<"\n";
    std::cout<<"Length of Nodes: "<<nodes.size()<<"\n";
    for(auto i: nodes)
        std::cout<<i->m_val<<"\n";

    return 0;
}