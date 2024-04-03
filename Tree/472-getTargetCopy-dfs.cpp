/**
 * @file 472-getTargetCopy-dfs.cpp
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.
 */
#include<iostream>

class TreeNode
{
    public:
        int m_val{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode(int v,TreeNode* l=nullptr,TreeNode* r=nullptr):m_val{v},left{l},right{r}{};
};



TreeNode* foo(TreeNode* a,TreeNode* b, TreeNode* target)
{
    if(!a)
        return nullptr;
    if(a->m_val==target->m_val)
        return b;
    foo(a->left,b->left,target);
    foo(a->right,b->right,target);
}




TreeNode* getTargetCopy(TreeNode* a,TreeNode* b, TreeNode* target)
{
    return foo(a,b,target);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // return bfs(cloned,target);
        if(original==nullptr||original==target)
            return cloned;
        
        auto left=getTargetCopy(original->left,cloned->left,target);
        if(left)
            return left;
        return getTargetCopy(original->right,cloned->right,target);
    }
private:
    // TreeNode* preOrder(TreeNode* root, TreeNode* target)
    // {
    //     if(!root)
    //         return nullptr;
    //     if(root->val==target->val)
    //         return root;
    //     TreeNode* left= preOrder(root->left,target);
    //     TreeNode* right= preOrder(root->right,target);
    //     return left?left:right;
    // }
    // TreeNode* bfs(TreeNode* root, TreeNode* target)
    // {
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         TreeNode* curNode=q.front();
    //         q.pop();
    //         if(curNode->val==target->val)
    //             return curNode;
    //         if(curNode->left)
    //             q.push(curNode->left);
    //         if(curNode->right)
    //             q.push(curNode->right);
    //     }
    //     return nullptr;
    // }
};