/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

#include<iostream>
#include<vector>

using namespace std;
using TN=struct TreeNode;

class Solution2 {
private:
    void inorder(TreeNode* root,vector<int>& nodes)
    {
        if(!root)   return;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        int minDiff=nodes.back();
        for(size_t i=1;i<nodes.size();++i)
            minDiff=min(minDiff,nodes[i]-nodes[i-1]);
        return minDiff;
        
    }
};


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
private:
    int* prev_;
    int minDiff;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(prev_)
            minDiff=min(minDiff,root->val-*prev_);
        prev_=&(root->val);
        inorder(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        minDiff=INT_MAX;
        prev_=nullptr;
        inorder(root);
        return minDiff;
    }
};

int main() {
  TN *root = new TN(10);
  TN *one = new TN(9);
  TN *two = new TN(12);

  root->left = one;
  // two->right=one;
  root->right = two;
  std::cout << Solution().getMinimumDifference(root);
}
