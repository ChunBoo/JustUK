

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
public:
  int subarrayBitwiseORs(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n));
    unordered_set<int> ans(begin(A), end(A));
    for (int l = 1; l <= n; ++l)
      for (int i = 0; i <= n - l; ++i) {
        int j = i + l - 1;
        if (l == 1) {
          dp[i][j] = A[i];
          continue;
        }
        dp[i][j] = dp[i][j - 1] | A[j];
        ans.insert(dp[i][j]);
      }
    return ans.size();
  }
};

int main()
{
    vector<int> nums{1,1,2};
    cout<<Solution().subarrayBitwiseORs(nums);
}