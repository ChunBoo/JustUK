#include<map>
#include<vector>
#include<iostream>


int sumOfUniqueNumbers(std::vector<int>& nums)
{
    if(nums.empty())
        return 0;
    int ans=0;
    std::map<int,int> m{};
    for(auto i:nums)
    {
        m[i]+=1;
    }
    for(auto v:m)
    {
        if(v.second==1)
            ans+=v.first;
    }
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,2,1,1,3,4};
    std::cout<<sumOfUniqueNumbers(nums);
    return 0;
}