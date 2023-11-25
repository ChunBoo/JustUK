/**
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }else if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }else{
            TreeNode* newRoot=nullptr;
            if(root->left==nullptr)
                newRoot=root->right;
            else if(root->right==nullptr)
                newRoot=root->left;
            else{
                TreeNode* parent=root;
                newRoot=root->right;
                while(newRoot->left!=nullptr){
                    parent=newRoot;
                    newRoot=newRoot->left;
                }
                if(parent!=root){
                    parent->left=newRoot->right;
                    newRoot->right=root->right;
                }
                newRoot->left=root->left;
            }
            delete root;
            return newRoot;
        }
        return root;
    }
        
    
};