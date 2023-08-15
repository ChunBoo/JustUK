/**
 * Given the root of a binary tree, the value of a target node target, and an
integer k, return an array of the values of all nodes that have a distance k
from the target node.

You can return the answer in any order.
 * Definition for a binary tree node.
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<TreeNode*,vector<TreeNode*>> g;
    void buildGraph(TreeNode* parent,TreeNode* child)
    {
      // create the graph from the binary tree
      if (parent) {
        g[parent].push_back(child);
        g[child].push_back(parent);
      }
        if (child->left)
          buildGraph(child, child->left);
        if(child->right) buildGraph(child,child->right);
    }
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(nullptr,root);
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(target);
        unordered_set<TreeNode *> seen{target};
        int _k = 0;
        while (!q.empty() && _k <= k) {
          int size = q.size();
          while (size--) {
            TreeNode *cur = q.front();
            q.pop();
            if (_k == k)
              ans.push_back(cur->val);
            for (auto &nxt : g[cur]) {
              if (seen.count(nxt))
                continue;
              seen.insert(nxt);
              q.push(nxt);
            }
          }
          ++_k;
        }
        return ans;
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