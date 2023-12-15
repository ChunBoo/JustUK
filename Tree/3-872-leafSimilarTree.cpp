/**
 * Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.


For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Note:

Both of the given trees will have between 1 and 100 nodes.
Solution: Recursion
Time complexity: O(n1 + n2)

Space complexity: O(n1 + n2)


*/

class Solution {
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leafs1;
    vector<int> leafs2;
    getLeafs(root1, leafs1);
    getLeafs(root2, leafs2);
    return leafs1 == leafs2;
  }
private:
  void getLeafs(TreeNode* root, vector<int>& leafs) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
      leafs.push_back(root->val);
    getLeafs(root->left, leafs);
    getLeafs(root->right, leafs);
  }
};