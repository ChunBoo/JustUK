#include<vector>
#include<iostream>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;


int Bag(VEC& w, VEC& v,int c)
{
    int n=w.size();

    MATRIX dp(n,VEC(c+1,0));

    for(int i=0;i<c;++i)
    {
        dp[0][i]=
    }
}