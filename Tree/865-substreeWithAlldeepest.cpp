/*Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    pair<int,TreeNode*> depth(TreeNode* root){
        if(!root)
            return {-1,nullptr};
        auto l=depth(root->left);
        auto r=depth(root->right);
        int dl=l.first;
        int dr=r.first;
        return {max(dl,dr)+1,dl==dr?root:(dl>dr)?l.second:r.second};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return depth(root).second;
    }
};

int main() {
  TreeNode *one = new TreeNode(1);
  TreeNode *two = new TreeNode(2);

  TreeNode *root = new TreeNode(3);
  TreeNode *four = new TreeNode(4);

  TreeNode *five = new TreeNode(5);
  TreeNode *six = new TreeNode(6);
  TreeNode *seven = new TreeNode(7);
  TreeNode *eight = new TreeNode(8);
  TreeNode *nine = new TreeNode(9);

  root->left = five;
  root->right = six;

  five->left = one;
  five->right = two;

  two->left = seven;
  two->right = four;

  six->left = eight;
  six->right = nine;

  cout << Solution().subtreeWithAllDeepest(root)->val;
}