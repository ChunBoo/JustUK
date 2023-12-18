/**
 * Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:

1
2
3
4
5
6
7
8
9
10
11
12
Input:
    1
   / \
  0   2
 
  L = 1
  R = 2
 
Output: 
    1
      \
       2
Example 2:
Input:
    3
   / \
  0   4
   \
    2
   /
  1
 
  L = 1
  R = 3
 
Output:
      3
     / 
   2   
  /
 1
*/

class Solution {
public:
    // No cleanup -> memory leak 
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return nullptr;
        // val not in range, return the left/right subtrees
        if(root->val < L) return trimBST(root->right, L, R);
        if(root->val > R) return trimBST(root->left, L, R);
        // val in [L, R], recusively trim left/right subtrees
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

#include <iostream>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    
    // With cleanup -> no memory leak
    TreeNode*& trimBST(TreeNode*& root, int L, int R) {
        if(!root) return root;
        
        if(root->val < L) {            
            auto& result = trimBST(root->right, L, R);
            deleteTree(root->left);
            delete root;
            root=nullptr;
            return result;
        } else if(root->val > R) {
            auto& result = trimBST(root->left, L, R);
            deleteTree(root->right);
            delete root;
            root=nullptr;
            return result;
        } else {
            // recusively trim left/right subtrees
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }
    
    void deleteTree(TreeNode* &root) {
        if(!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root=nullptr;
    }
};
 
void PrintTree(TreeNode* root) {
    if(!root) {
        cout<<"null ";
        return;
    };
    if(!root->left && !root->right) {
        cout<<root->val<<" ";
    } else {
        cout<<root->val<<" ";
        PrintTree(root->left);
        PrintTree(root->right);
    }
}
 
 
int main()
{
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);
    PrintTree(root);
    std::cout<<std::endl;
    
    TreeNode* t = Solution().trimBST(root, 3, 4);
    PrintTree(t);
    std::cout<<std::endl;
 
    // Original root was deleted
    PrintTree(root);
    std::cout<<std::endl;
    
    return 0;
}