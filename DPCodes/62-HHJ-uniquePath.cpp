
/**
 * A robot is located at the top-left corner of a m x n grid (marked ‘Start’ in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?


*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[1][1]=1;
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j){
                if(i==1&&j==1) continue;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
        // auto f = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        // f[1][1] = 1;
        
        // for (int y = 1; y <= n; ++y)
        //     for(int x = 1; x <= m; ++x) {
        //         if (x == 1 && y == 1) {
        //             continue;
        //         } else {
        //             f[y][x] = f[y-1][x] + f[y][x-1];
        //         }
        //     }
        
        // return f[n][m];
    }
};