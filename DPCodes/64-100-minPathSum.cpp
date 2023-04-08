#include<vector>
#include<iostream>

using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;

int minPathsSum(const MATRIX& grid)
{
    int R=grid.size(),C=grid[0].size();
    MATRIX dp(R,VEC(C,0));
    dp[0][0]=grid[0][0];
    for(int i=1;i<R;++i)
        dp[i][0]=dp[i-1][0]+grid[i][0];
    for(int j=1;j<C;++j)
        dp[0][j]=dp[0][j-1]+grid[0][j];
    
    for(int r=1;r<R;++r)
    {
        for(int c=1;c<C;++c)
        {
            dp[r][c]=std::min(dp[r-1][c],dp[r][c-1])+grid[r][c];
        }
    }
    return dp[R-1][C-1];
}

int main()
{
    MATRIX grid{{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathsSum(grid);
}