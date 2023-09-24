/**
 * ou are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.

 
*/
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int kMod=1e9+7;
        int m=grid.size(),n=grid[0].size();
        auto f=vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(k)));
        f[0][0][grid[0][0]%k]=1;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                if(i==0&&j==0) continue;
                for(int r=0;r<k;++r)
                    f[i][j][(r+grid[i][j])%k]=((j?f[i][j-1][r]:0)+(i?f[i-1][j][r]:0))%kMod;
            }
            return f[m-1][n-1][0];
    }
};