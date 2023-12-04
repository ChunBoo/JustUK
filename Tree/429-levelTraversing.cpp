/*Given an n-ary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

For example, given a 3-ary tree:

 


 

We should return its level order traversal:

[
     [1],
     [3,2,4],
     [5,6]
]
Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.
Solution1: Recursion
Time complexity: O(n)

Space complexity: O(n)

*/
class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    preorder(root, 0, ans);
    return ans;
  }
private:
  void preorder(Node* root, int d, vector<vector<int>>& ans) {
    if (root == nullptr) return;
    while (ans.size() <= d) ans.push_back({});
    ans[d].push_back(root->val);
    for (auto child : root->children)
      preorder(child, d + 1, ans);
  }
};
//Solution2: Iterative

class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) return {};
    vector<vector<int>> ans;    
    queue<Node*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      int size = q.size();
      ans.push_back({});
      while (size--) {
        Node* n = q.front(); q.pop();
        ans[depth].push_back(n->val);
        for (auto child : n->children)
          q.push(child);
      }
      ++depth;
    }
    return ans;
  }
};