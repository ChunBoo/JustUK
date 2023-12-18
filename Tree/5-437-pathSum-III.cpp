/*You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
Solution 1: Recursion
Time complexity: O(n^2)

Space complexity: O(n)

*/
class Solution {
public:
  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    return numberOfPaths(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }
private:
  int numberOfPaths(TreeNode* root, int left) {
    if (!root) return 0;    
    left -= root->val;
    return (left == 0 ? 1 : 0) + numberOfPaths(root->left, left) + numberOfPaths(root->right, left);
  }
};

public:
  int pathSum(TreeNode* root, int sum) {
    ans_ = 0;
    sums_ = {{0, 1}};
    pathSum(root, 0, sum);
    return ans_;
  }
private:
  int ans_;
  unordered_map<int, int> sums_;
  
  void pathSum(TreeNode* root, int cur, int sum) {
    if (!root) return;
    cur += root->val;
    ans_ += sums_[cur - sum];
    ++sums_[cur];
    pathSum(root->left, cur, sum);
    pathSum(root->right, cur, sum);
    --sums_[cur];
  }
};