//element value worked as index
#include<iostream>
#include<vector>

std::vector<int> createList(const std::vector<int>& nums)
{
    std::vector<int> ans{};
    for(int i=0;i<nums.size();++i)
    {
        ans.push_back(nums[nums[i]]);
    }
    return ans;
}

int main()
{
    std::vector<int> l{2,1,4,3};  //this list can not work
    std::vector<int> ret=createList(l);
    for(auto v:ret)
        std::cout<<v;
    return 0;
    
}