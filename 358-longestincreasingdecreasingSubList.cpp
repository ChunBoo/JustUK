#include<vector>
#include<iostream>
#include<algorithm>

using VEC=std::vector<int>;


int longestincreasingdecreasingSubList(const VEC& nums)
{
    int sz=nums.size();
    VEC inc(sz,1);
    VEC dec(sz,1);

    for(int i=1;i<sz;++i)
    {
        if(nums[i]>nums[i-1])
            inc[i]+=inc[i-1];

    }
    for(int i=sz-2;i>-1;--i)
    {
        if(nums[i]>nums[i+1])
            dec[i]+=dec[i+1];
    }
    int ans=0;
    for(int i=0;i<sz;++i)
    {
        if(inc[i]>1 &&dec[i]>1)
        {
            ans=std::max(ans,inc[i]+dec[i]-1);
        }
    }
    return ans;
}

int main()
{
    VEC nums{2,3,1,3,5,3,0,1,3,2,2};
    std::cout<<(longestincreasingdecreasingSubList(nums));
}