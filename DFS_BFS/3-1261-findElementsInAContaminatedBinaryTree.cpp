/**
 * @file 3-1261-findElementsInAContaminatedBinaryTree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-12
 * 
 * @copyright Copyright (c) 2024

  Given a binary tree with the following rules:

root.val == 0
If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.
 */


// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// enum Child{ 
//     LEFT,
//     RIGHT,
//     ROOT,
// };

// class FindElements {
// public:

//     FindElements(TreeNode* root) 
//     {
//         dfs(root,0,ROOT);
//         for(int v:nodes_)
//             cout<<v<<',';
//     }
    
//     bool find(int target) 
//     {
//         return nodes_.count(target);
//     }
// private:
//     set<int> nodes_;
//     void dfs(TreeNode* root,int d,Child side)
//     {
//         int val=0;
//         if(side==ROOT)
//             nodes_.insert(0);
//         else
//         {
//             if(side==LEFT)
//             {
//               val=2*d+1;
//               nodes_.insert(val);
//             }
//             else 
//             {
//               val=2*d+2;
//               nodes_.insert(val);
//             }
//         }
//         if(root->left)
//             dfs(root->left,val,LEFT);
//         if(root->right)
//             dfs(root->right,val,RIGHT);
//     }
// };

// /**
//  * Your FindElements object will be instantiated and called as such:
//  * FindElements* obj = new FindElements(root);
//  * bool param_1 = obj->find(target);
//  */

class FindElements {
private:
    unordered_set<int> valSet;

    void dfs(TreeNode *node, int val) {
        if (node == nullptr) {
            return;
        }
        node->val = val;
        valSet.insert(val);
        dfs(node->left, val * 2 + 1);
        dfs(node->right, val * 2 + 2);
    }

public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }

    bool find(int target) {
        return valSet.count(target) > 0;
    }
};

