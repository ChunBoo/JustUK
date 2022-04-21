#include<iostream>
#include<vector>

std::vector<int> concatArray(std::vector<int>& nums)
{
    std::vector<int> ans{nums};
    int sz=nums.size();
    for(int i=0;i<sz;++i)
        ans.push_back(nums[i]);
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,3};
    std::vector<int> ret=concatArray(nums);

    for(auto i:ret)
        std::cout<<i<<',';
    return 0;
}