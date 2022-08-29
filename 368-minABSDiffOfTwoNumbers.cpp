#include<vector>
#include<iostream>
#include<algorithm>

using VEC=std::vector<int>;


std::vector<VEC> minABSDiffOfTwoNumbers(VEC& nums)
{
    std::vector<VEC> ans{};
    std::sort(nums.begin(),nums.end());

    int minDiff=INT_MAX;

    for(int i=1;i<nums.size();++i)
    {
        minDiff=std::min(nums[i]-nums[i-1],minDiff);
    }

    for(int i=1;i<nums.size();++i)
    {
        int curMin=nums[i]-nums[i-1];
        if(curMin==minDiff)
        {
            ans.push_back(VEC{nums[i-1],nums[i]});
        }
    }
    return ans;
}

int main()
{
    VEC nums{3,4,100,30,20,19,21};
    std::vector<VEC> res=minABSDiffOfTwoNumbers(nums);
    for(auto _v:res)
    {
        std::cout<<'\n';
        for(auto v:_v)
        {
            std::cout<<v<<',';
        }
    }
    return 0;
}