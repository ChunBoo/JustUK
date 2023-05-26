#include<iostream>
#include<vector>
#include<cmath>

using std::cout;
using VEC=std::vector<int>;

int dp(const VEC& nums,int i)
{
    if(i==0)
        return nums[i];
    return std::max(0,dp(nums,i-1))+nums[i];
}

int maxSubArray(const VEC& nums)
{
    int ans=0;
    for(size_t i=0;i<nums.size();++i)
    {
        ans=std::max(ans,dp(nums,i));
    }
    return ans;
}

int main()
{
    VEC nums{-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
}