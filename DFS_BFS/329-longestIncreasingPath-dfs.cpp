/**
 * Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m_;
    int n_;
    vector<vector<int>> dp_;
    int dfs(const vector<vector<int>> &mat, int r, int c) {
      if (dp_[r][c] > 0)
        return dp_[r][c];
      dp_[r][c] = 1;
      static int dirs[]{0, -1, 0, 1, 0};

      for (int i = 0; i < 4; ++i) {
        int tr = r + dirs[i];
        int tc = c + dirs[i + 1];
        if (tr < 0 || tc < 0 || tr >= m_ || tc >= n_ ||
            mat[tr][tc] <= mat[r][c])
          continue;
        dp_[r][c] = max(dp_[r][c], 1 + dfs(mat, tr, tc));
      }
      return dp_[r][c];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        m_=matrix.size();
        n_=matrix[0].size();
        dp_ = vector<vector<int>>(m_, vector<int>(n_, 0));
        int ans=0;

        for (int r = 0; r < m_; ++r) {
          for (int c = 0; c < n_; ++c) {
            ans = max(ans, dfs(matrix, r, c));
          }
        }
        return ans;
    }
};

class Solution2 { // bottom-up

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1));

        int ans=0;
        vector<pair<int,pair<int,int>>> cells;
        for(int y=0;y<m;++y)
            for(int x=0;x<n;++x)
                cells.push_back({matrix[y][x],{x,y}});
        sort(cells.rbegin(),cells.rend());

        vector<int> dirs{0,1,0,-1,0};

        for(const auto& cell:cells)
        {
            int x=cell.second.first;
            int y=cell.second.second;//row
            for(int i=0;i<4;++i){
                int tx=x+dirs[i];
                int ty=y+dirs[i+1];
                if(tx<0||tx>=n||ty<0||ty>=m) continue;
                if(matrix[ty][tx]<=matrix[y][x]) continue;
                dp[y][x]=max(dp[y][x],1+dp[ty][tx]);
            }
            ans=max(ans,dp[y][x]);
        }
        return ans;
    }
};

int main() {
  vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  cout << Solution().longestIncreasingPath(matrix);
}