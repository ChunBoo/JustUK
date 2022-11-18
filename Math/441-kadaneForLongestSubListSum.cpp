#include<vector>
#include<iostream>
#include<algorithm>

using VEC=std::vector<int>;

int longestSubList(const VEC& nums)
{
    if(nums.empty())
        return 0;

    int ans{std::abs(nums[0])};
    int low=nums[0],high=nums[0];
    for(auto &v:nums)
    {
        low=std::min(low+v,v);
        high=std::max(high+v,v);
        ans=std::max({ans,-low,std::abs(high)});
    }
    return ans;
}

int main()
{
    VEC nums{1,2,3,-5,-6};
    std::cout<<longestSubList(nums);
}