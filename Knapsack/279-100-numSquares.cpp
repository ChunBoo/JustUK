#include<iostream>
#include<vector>
#include<cmath>

using VEC=std::vector<int>;
using std::cout;

int numSquares(int n)
{
    VEC dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;++i)   //knapsack
    {
        for(int j=1;j<=(int)(sqrt(i));++j)
        {
            dp[i]=std::min(dp[i-j*j]+1,dp[i]);
        }
    }
    return dp[n];
}

int main()
{
    cout<<numSquares(12);
}