#include<iostream>
#include<vector>

std::vector<int> createList(const std::vector<int>& nums)
{
    std::vector<int> ans{};
    for(auto i:nums)
    {
        ans.push_back(nums[i]);
    }
    return ans;
}

int main()
{
    std::vector<int> l{2,1,0,3};
    std::vector<int> ret=createList(l);
    for(auto v:ret)
        std::cout<<v;
    return 0;
    
}