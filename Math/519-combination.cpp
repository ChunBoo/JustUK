#include<vector>
#include<iostream>

using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;

long long combinations(int m,int n)  //recursion method
{
    if(m>n)
        return 0;
    if(m==n ||m==0)
        return 1;
    return combinations(m-1,n-1)+combinations(m,n-1);
}

long long combinationsIteration(int m,int n)
{
    if(m>n)
        return 0;
    if(m==n ||m==0)
        return 1;
    MATRIX dp(n+1,std::vector<int>(m+1,0));
    for(int i=0;i<n+1;++i)
    {
        dp[i][0]=1;
    }
    for(int i=0;i<m+1;++i)
        dp[i][i]=1;
    for(int i=1;i<n+1;++i)  //should be start from 1
    {
        for(int j=1;j<std::min(i,m+1);++j)  //should be start from 1
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    return dp[n][m];
}



int main()
{
    cout<<combinations(2,3);
    cout<<combinationsIteration(2,3);
}