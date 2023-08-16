/**
 *
 * 
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]
Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.
 * 
 * 
*/
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    ans.clear();
    dis(root, target, K);
    return ans;
  }
private:
  vector<int> ans;
  // Returns the distance from root to target.
  // Returns -1 if target does not in the tree.
  int dis(TreeNode* root, TreeNode* target, int K) {
    if (root == nullptr) return -1;
    if (root == target) {
      collect(target, K);
      return 0;
    }
    
    int l = dis(root->left, target, K);
    int r = dis(root->right, target, K);
    
    // Target in the left subtree
    if (l >= 0) {
      if (l == K - 1) ans.push_back(root->val);
      // Collect nodes in right subtree with depth K - l - 2
      collect(root->right, K - l - 2);
      return l + 1;
    }
    
    // Target in the right subtree
    if (r >= 0) {
      if (r == K - 1) ans.push_back(root->val);
      // Collect nodes in left subtree with depth K - r - 2
      collect(root->left, K - r - 2);
      return r + 1;
    }
    return -1;
  }
  
  // Collect nodes that are d steps from root.
  void collect(TreeNode* root, int d) {
    if (root == nullptr || d < 0) return;
    if (d == 0) ans.push_back(root->val);
    collect(root->left, d - 1);
    collect(root->right, d - 1);
  }
};

int main() {
  TreeNode *root = new TreeNode(3);
  TreeNode *one = new TreeNode(1);
  TreeNode *two = new TreeNode(2);
  TreeNode *four = new TreeNode(4);
  TreeNode *five = new TreeNode(5);
  TreeNode *six = new TreeNode(6);
  TreeNode *seven = new TreeNode(7);

  root->left = five;
  root->right = one;
  five->left = six;
  five->right = seven;
  seven->left = two;
  seven->right = four;
  int k = 1;
  vector<int> res = Solution().distanceK(root, five, k);
  for (int v : res)
    cout << v << ',';
}