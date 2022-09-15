#include<vector>
#include<iostream>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;


int Bag(VEC& w, VEC& v,int c)
{
    int n=w.size();
    MATRIX dp(n,VEC(c+1,0));

    //initialize the first row

    for(int i=0;i<c+1;++i)
    {
        dp[0][i]=(i>=w[0])?v[0]:0;
    }

    for(int i=1;i<n;++i)
    {
        for(int j=0;j<c+1;++j)
        {
            int pick=(j>=w[i])?(dp[i-1][j-w[i]]+v[i]):0;
            dp[i][j]=std::max(dp[i-1][j],pick);
        }
    }
    return dp[n-1][c];
}

int main()
{
    VEC weights{1,2,3};
    VEC values{1,5,3};
    std::cout<<Bag(weights,values,5);
}