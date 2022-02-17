#include "treeNode.h"
#include<iostream>
#include<vector>
#include<map>
TreeNode* buildTree(std::map<int,int>& inMap,std::vector<int>& preorder,int preStart,int preEnd,std::vector<int>& inorder,int inStart,int inEnd)
{
    if(preEnd<preStart)
        return nullptr;
    
    int rootValue=preorder[preStart];
    int rootIndex=inMap[rootValue];
    int numberOfLeftNodes=rootIndex-inStart;

    TreeNode* root=new TreeNode(rootValue);
    root->left=buildTree(inMap,preorder,preStart+1,preStart+numberOfLeftNodes,inorder,inStart,rootIndex);
    root->right=buildTree(inMap,preorder,preStart+numberOfLeftNodes+1,preEnd,inorder,inStart+numberOfLeftNodes+1,inEnd);
    return root;
}

TreeNode* createBTByPreorderAndInorder( std::vector<int>& preorder,std::vector<int>& inorder)
{
    if(preorder.empty()||inorder.empty())
        return nullptr;

    int sz=inorder.size();
    std::map<int,int> inMap{};
    for(int idx=0;idx<sz;++idx)
    {   
        inMap[inorder[idx]]=idx;
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
    root->printTreeInOrder(root);
    return 0;
}
