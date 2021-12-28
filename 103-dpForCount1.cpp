//dp for count 1 in a integer

#include<vector>
#include<iostream>

void dpForCount1(int n,std::vector<int>& dp)
{
    // std::vector<int> dp{0,n};
    // if(n==0)
    //     dp.push_back(0);
    // if(n==1)
    //     dp.push_back(1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n+1;++i)
    {
        dp[i]=(dp[i&(i-1)]+1);
    }
    // return dp;
}

int main()
{
    int i=8;
    std::vector<int> res(9);
    dpForCount1(8,res);
    for(auto i: res)
        std::cout<<i<<"-";
    return 0;
}