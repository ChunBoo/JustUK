#include<vector>
#include<iostream>
#include<map>

int countOfSubList(std::vector<int>& nums)
{
    int ans=0;
    std::map<int,int> seen{};
    for(auto i:nums)
    {
        seen[i]+=1;
        ans+=seen[i];
    }
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,3,5,1};
    std::cout<<countOfSubList(nums);
    return 0;
}