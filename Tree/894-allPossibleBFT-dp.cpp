#include<vector>
#include<iostream>

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


vector<TreeNode*> allPossibleBFT(int n)
{
    if(n%2==0) return {};
    if(n==1) return {new TreeNode(0)};

    vector<vector<TreeNode*>> dp(n+1);
    dp[1]={new TreeNode(0)};

    for(int i=3;i<=n;i+=2)
    {
        for(int j=1;j<i;j+=2)
        {
            int k=i-j-1;
            for(auto &l:allPossibleBFT(j))
            {
                for(auto &r:allPossibleBFT(k))
                {
                    auto root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    dp[i].push_back(root);  //here is dp[i]
                }
            }
        }
    }
    return dp[n];
}

int main()
{
  vector<TreeNode *> res = allPossibleBFT(7);
  for (const auto &n : res)
    cout << n->val << ',';
}