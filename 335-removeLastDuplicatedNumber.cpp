#include<map>
#include<vector>
#include<iostream>

using DT=std::vector<int>;
using MAP=std::map<int,int>;
void counter(const DT& nums,MAP& m)
{
    if(nums.empty())
        return;
    int sz=nums.size();
    for(int i=0;i<sz;++i)
    {
        m[nums[i]]+=1;
    }
}

DT removeLastDuplicatedElements(const DT& nums)
{
    MAP m{};
    MAP last{};
    counter(nums,m);
    int sz=nums.size();
    DT res{};
    for(int i=0;i<sz;++i)
    {
        last[nums[i]]=i;
    }
    for(int i=0;i<sz;++i)
    {
        if(m[nums[i]]==1 || last[nums[i]]!=i)
            res.push_back(nums[i]);
    }
    return res;    
}

int main()
{
    DT nums{1, 1, 1, 2, 2, 2, 3, 3, 3};
    DT res=removeLastDuplicatedElements(nums);
    for(auto &i:res)
        std::cout<<i<<',';
}