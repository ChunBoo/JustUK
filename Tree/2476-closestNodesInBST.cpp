// Definition for a binary tree node.
// findout :
// 1.the max value which less than the queried value;
// 2. min value which large than quried value,
// 3.if can not find,return -1
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> m_data;
    void preTraverse(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
            preTraverse(root->left);
        m_data.push_back(root->val);
        if(root->right)
            preTraverse(root->right);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        if(!root)
            return {{-1,-1}};
        preTraverse(root);
        for(auto i:m_data)
            cout<<i<<',';
        vector<vector<int>> ans;
        for(auto &v:queries){
            vector<int> cur{-1,-1};
            auto left =
                upper_bound(m_data.begin(), m_data.end(), v); // upper_bound,
            if(left!=m_data.begin())
                cur[0]=*prev(left);
            auto right=lower_bound(m_data.begin(),m_data.end(),v);
          
            if(right!=m_data.end())
                cur[1]=*right;
            ans.push_back(std::move(cur));
        }
        return ans;
    }
};

class Solution2 {
private:
  vector<int> m_data;
  void preTraverse(TreeNode *root) {
    if (!root)
      return;
    if (root->left)
      preTraverse(root->left);
    if (m_data.empty() || root->val > m_data.back()) // optimized case
      m_data.push_back(root->val);
    if (root->right)
      preTraverse(root->right);
  }

public:
  vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
    if (!root)
      return {{-1, -1}};
    preTraverse(root);
    vector<vector<int>> ans;
    // for (const int q : queries) {
    //   vector<int> cur{-1, -1};
    //   auto it = lower_bound(begin(m_data), end(m_data), q);
    //   if (it != end(m_data) && *it == q)
    //     cur[0] = cur[1] = q;
    //   else {
    //     if (it != begin(m_data))
    //       cur[0] = *prev(it);
    //     if (it != end(m_data))
    //       cur[1] = *it;
    //   }
    //   ans.push_back(std::move(cur));
    for (auto &v : queries) {
      cout << v << '\n';
      vector<int> cur{-1, -1};
      auto it = lower_bound(begin(m_data), end(m_data), v);
      if (*it == v && (it != end(m_data)))
        cur[0] = cur[1] = v;
      else {
        if (it != begin(m_data))
          cur[0] = *prev(it);
        if (it != end(m_data))
          cur[1] = *it;
      }
      ans.push_back(cur);
    }
    return ans;
  }
};

int main() {
  TreeNode *root = new TreeNode(6);
  TreeNode *one = new TreeNode(1);
  TreeNode *five = new TreeNode(5);
  TreeNode *four = new TreeNode(4);
  TreeNode *seven = new TreeNode(7);
  TreeNode *nine = new TreeNode(9);
  TreeNode *ten = new TreeNode(10);

  root->left = four;
  root->right = nine;
  four->left = one;
  four->right = five;

  nine->left = seven;
  nine->right = ten;

  vector<int> queries{2, 4, 16};
  vector<vector<int>> res = Solution2().closestNodes(root, queries);

  for (auto &v : res) {
    cout << '\n';
    for (auto &n : v)
      cout << n << ',';
  }
}