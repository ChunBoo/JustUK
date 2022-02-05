#include "treeNode.h"
#include<iostream>
#include<vector>
#include<map>
TreeNode* buildTree(std::map<int,int>& inMap,std::vector<int>& preorder,int preStart,int preEnd,std::vector<int>& inorder,int inStart,int inEnd)
{
    if(preStart>preEnd)
        return nullptr;
    TreeNode* root=new TreeNode(preorder[preStart]);
    int inRoot=inMap[preorder[preStart]];
    int cntOfLeft=inRoot-inStart;
    root->left=buildTree(inMap,preorder,preStart+1,cntOfLeft+preStart,inorder,inStart,inRoot-1);
    root->right=buildTree(inMap,preorder,preStart+cntOfLeft+1,preEnd,inorder,inRoot+1,inEnd);
    return root;
}

TreeNode* createBTByPreorderAndInorder( std::vector<int>& preorder,std::vector<int>& inorder)
{
    std::map<int,int> inMap{};
    int sz=preorder.size();
    for(int i=0;i<sz;++i)
    {
        inMap[inorder[i]]=i;
    }
    return buildTree(inMap,preorder,0,sz-1,inorder,0,sz-1);
}

int main()
{
//     std::string preorder{"123"};
//     std::string inorder{"213"};
    // std::cout<<inorder.substr(0,2);
    std::vector<int> preorder{1,2,3};
    std::vector<int> inorder{2,1,3};
    TreeNode* root=createBTByPreorderAndInorder(preorder,inorder);
    root->printTreeInorder(root);
    return 0;
}
