


#include<iostream>
#include<vector>
#include<cmath>

using std::cout;
using VEC=std::vector<int>;

int dp(int i,int j,const VEC& nums)
{
    if(j<i)
        return 0;
    
    return std::max(dp(i,j-2,nums)+nums[j],dp(i,j-1,nums));
}

int robber2(const VEC& nums)
{
    int sz=nums.size();
    if(sz==1)
        return nums[0];
    return std::max(dp(0,sz-2,nums),dp(1,sz-1,nums));
}

int main()
{
    VEC nums{2,3,2};
    cout<<robber2(nums);
}