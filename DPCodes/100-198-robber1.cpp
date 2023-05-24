#include<iostream>
#include<vector>
#include<cmath>

using std::cout;
using VEC=std::vector<int>;


int dp(const VEC& nums,int i)
{
    if(i<0)
        return 0;
    return std::max(dp(nums,i-2)+nums[i],dp(nums,i-1));
}

int rob1(const VEC& nums)
{
    int sz=nums.size();
    if(sz==1)
        return nums[0];
    return dp(nums,sz-1);
}

int main()
{
    VEC nums{1,2,3,1};
    cout<<rob1(nums);
}