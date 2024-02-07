
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

class Solution {
public:
    int uniquePaths(int m, int n) {
        // if(m<0||n<0)
        //     return 0;
        // if(m==1&&n==1)
        //     return 1;
        // if(f_[m][n]>0) return f_[m][n];
        // int left=uniquePaths(m,n-1);
        // int top=uniquePaths(m-1,n);
        //  f_[m][n]=left+top;
        //  return f_[m][n];
         if(m<0||n<0)
            return 0;
        vector<vector<int>> f(m+1,vector<int>(n+1,0));
        f[1][1]=1;
        for(int r=1;r<=m;++r)
            for(int c=1;c<=n;++c)
            {
                if(r==1&&c==1)
                  continue;
                f[r][c]=f[r-1][c]+f[r][c-1];
            }
         return f[m][n];

    }
// private:
//     unordered_map<int,unordered_map<int,int>> f_;
};