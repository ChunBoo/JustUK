/**
 * Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.
*/

enum class State { NONE = 0, COVERED = 1, CAMERA = 2 };
 
class Solution {
public:
  int minCameraCover(TreeNode* root) {        
    if (dfs(root) == State::NONE) ++ans_;
    return ans_;
  }
private:  
  int ans_ = 0;
  State dfs(TreeNode* root) {
    if (!root) return State::COVERED;
    State l = dfs(root->left);
    State r = dfs(root->right);
    if (l == State::NONE || r == State::NONE) {
      ++ans_;
      return State::CAMERA;
    }
    if (l == State::CAMERA || r == State::CAMERA)
      return State::COVERED;    
    return State::NONE;
  }
};