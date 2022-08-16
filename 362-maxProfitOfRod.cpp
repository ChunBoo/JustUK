#include<iostream>
#include<vector>
using VEC=std::vector<int>;
int dfs(int n,VEC& prices)
{
    if(n<=0)
        return 0;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans=std::max(ans,dfs(n-i-1,prices)+prices[i]);
    }
    return ans;
}

int maxProfit(int n,VEC& prices)
{
    int ans=0;
    return dfs(n,prices);
    // return ans;
}

int main()
{
    VEC prices{1, 3, 5, 7, 7, 7};
    std::cout<<maxProfit(6,prices);
}