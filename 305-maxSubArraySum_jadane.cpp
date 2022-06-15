//subArray means the values are continuous,
//subsequence means the values can be selected
#include<iostream>
#include<vector>
#include<cmath>
using DT=std::vector<int>;

int maxSubArraySum(const DT& nums)
{
    int dpi=0,ans=INT_MIN;
    for(auto &i:nums)
    {
        dpi=std::max(dpi+i,i);
        ans=std::max(ans,dpi);
    }
    return ans;
}

int main()
{
    DT nums{-2,1,10};
    std::cout<<maxSubArraySum(nums);
    return 0;
}