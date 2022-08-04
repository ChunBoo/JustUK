#include<map>
#include<vector>
#include<iostream>

using DT=std::vector<int>;
using MAP=std::map<int,int>;  //here the map is ordered

MAP myCounter(const DT& nums)
{
    MAP ret{};
    for(auto &v:nums)
    {
        ret[v]+=1;
    }
    return ret;
}

DT countSorting(const DT& nums)
{
    DT ans{};
    if(nums.empty())
        return ans;
    
    MAP data=myCounter(nums);

    std::map<int,int>::iterator iter=data.begin();
    for(;iter!=data.end();++iter)
    {
        if(iter->second>0)
        {
            DT tmp(iter->second, iter->first);
            ans.reserve(ans.size()+distance(tmp.begin(),tmp.end()));
            ans.insert(ans.end(),tmp.begin(),tmp.end());
        }
    }
    return ans;
}

int main()
{
    DT nums{1,3,2,5,2,1,10};
    DT res=countSorting(nums);
    for(auto &i:res)
        std::cout<<i<<',';

    return 0;
}