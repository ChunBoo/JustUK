

#include<iostream>
#include<vector>

using MATRIX=std::vector<std::vector<int>>;
using VEC=std::vector<int>;

MATRIX subSets(const VEC& nums)
{
    MATRIX ans{};
    if(nums.empty())
        return ans;
    ans.push_back(std::vector<int>{});
    for(auto &v:nums)
    {
        MATRIX tmp{ans.begin(),ans.end()};
        for(auto m:tmp)
        {
            m.push_back(v);
            tmp.push_back(m);
        }
        for(auto _m:tmp)
            ans.push_back(_m);
    }
    return ans;
}


int main()
{
    VEC nums{1,2,3};
    MATRIX res=subSets(nums);
    for(auto &v:res)
    {
        std::cout<<'\n';
        for(auto &i:v)
            std::cout<<i<<',';
    }
}