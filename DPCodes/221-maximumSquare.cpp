
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> sums_;
public:
  int maximalSquare(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    sums_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        sums_[i][j] = matrix[i - 1][j - 1] + sums_[i][j - 1] + sums_[i - 1][j] -
                      sums_[i - 1][j - 1];
      }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = min(m - i + 1, n - j + 1); k > 0; --k) {
          int tmp = sums_[i + k - 1][j + k - 1] - sums_[i + k - 1][j - 1] -
                    sums_[i - 1][j + k - 1] + sums_[i - 1][j - 1];
          if (tmp == k * k) {
            ans = max(tmp, ans);
            break;
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> m = {
      //   {1, 0, 1},//, 0, 0},
      {1, 1, 1}, // 1, 1},
      {1, 0, 1}  // 1, 1},
                 //   {1, 0, 0, 1, 0}
  };
  cout << Solution().maximalSquare(m);
}