#include"treeNode.h"

#include<vector>

TreeNode* copyATree(TreeNode* root)
{
    if(!root)
        return root;
    
    TreeNode* newRoot=new TreeNode(root->m_val);
    newRoot->left=copyATree(root->left);
    newRoot->right=copyATree(root->right);

    return newRoot;
}

bool isSymmetricTree(TreeNode* a,TreeNode* b)  //judge two tress are symmetric or not
{
    if(!a &&!b)
        return true;
    
    if(!a || !b)
        return false;
    
    if(a->m_val!=b->m_val)
        return false;
    return(isSymmetricTree(a->left,b->right) && isSymmetricTree(a->right,b->left));
}

TreeNode* revertBST(TreeNode* root)//revert a tree,  left->right? right->left
{
    if(!root)
        return root;

    TreeNode* left=revertBST(root->left);
    TreeNode* right=revertBST(root->right);
    root->left=right;
    root->right=left;
    return root;
}

int main()
{
    std::vector<int> nums{1,2,3,4,5,6};
    #if 0
    TreeNode* root=new TreeNode(1);
    TreeNode* leftNode=new TreeNode(2);
    leftNode->addLeftChild(3);
    leftNode->addRightChild(4);
    TreeNode* rightNode=new TreeNode(5);
    rightNode->addLeftChild(6);
    rightNode->addRightChild(7);

    root->left=leftNode;
    root->right=rightNode;

    root->printTreeInOrder(root);
    std::cout<<'\n';
    TreeNode* newHead= revertBST(root);
    newHead->printTreeInOrder(newHead);
    std::cout<<"\n After copying:\n";
    TreeNode* newRoot=copyATree(root);
    newRoot->printTreeInOrder(newRoot);
#endif

    //symmetric tree test

    TreeNode* root=new TreeNode(0);
    root->addLeftChild(1);
    root->addRightChild(2);
    
    std::cout<<"tree is symmetric?"<<(isSymmetricTree(root->left,root->right)?"Yes":"No")<<'\n';
    return 0;
    
}