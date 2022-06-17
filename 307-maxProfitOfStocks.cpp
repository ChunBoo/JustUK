#include<iostream>
#include<vector>
#include<cmath>
using DT=std::vector<int>;

int maxProfit(const DT& p)
{
    int ans=INT_MIN,minVal=INT_MAX;
    for(auto &v:p)
    {
        minVal=std::min(minVal,v);
        ans=std::max(ans,v-minVal);
    }
    return ans;
}

int maxProfitKadane(const DT& prices)
{
    int ans=0,maxP=0;
    int n=prices.size();
    for(int i=1;i<n;++i)
    {
        maxP=std::max(prices[i]-prices[i-1]+maxP,0);
        ans=std::max(ans,maxP);
    }
    return ans;
}


int main()
{
    DT nums{1,0,3,6,9};
    std::cout<<maxProfit(nums);
    std::cout<<maxProfitKadane(nums);
    return 0;
}