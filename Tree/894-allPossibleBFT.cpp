/**
 * Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

 

Example 1:


Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Example 2:

Input: n = 3
Output: [[0,0,0]]
 

Constraints:

1 <= n <= 20
 * 
*/

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

#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        if(n==1) return {new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
            for(auto l :allPossibleFBT(i))
                for(auto r:allPossibleFBT(n-i-1)){
                    auto root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
        }
        return ans;
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
static constexpr int kMaxN=20+1;
static array<vector<TreeNode*>,kMaxN> m;

class Solution2 {
private:
    vector<TreeNode*>& trees(int n){
        if(m[n].size()>0) return m[n];
        vector<TreeNode*>& ans=m[n];
        if(n%2==0) return ans={};
        if(n==1) ans={new TreeNode(0)};
                for(int i=1;i<n;i+=2){
            for(const auto& l :trees(i))
                for(const auto& r:trees(n-i-1)){
                    auto root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
        }
        return ans;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return trees(n);
    }
};

int main() {
  vector<TreeNode *> res = Solution().allPossibleFBT(7);
  for (const auto &n : res)
    cout << n->val << ',';
}