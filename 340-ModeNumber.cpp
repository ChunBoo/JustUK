//given one array, get the first value which it occurred most times

#include<vector>
#include<iostream>
#include<map>
#include<algorithm>

using DT=std::vector<int>;
using MAP=std::map<int,int>;
void counter(const DT& nums,MAP& m)
{
    if(nums.empty())
        return;
    for(auto &v:nums)
        m[v]+=1;
}


int modeNumber(const DT& nums)
{
    MAP m{};
    counter(nums,m);
    MAP::iterator iter=m.begin();
    int max=0,res=INT_MIN;
    for(;iter!=m.end();++iter)
    {
        if(iter->second>max)
        {
            max=iter->second;
            res=iter->first;
        }
    }
    return res;
}


int main()
{
    DT nums{1,2,2,2,3,3,3,4,4,4,4};
    int res=modeNumber(nums);
    std::cout<<res<<'\n';
}

