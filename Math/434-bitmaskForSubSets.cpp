#include<iostream>
#include<vector>

using MATRIX=std::vector<std::vector<int>>;
using VEC=std::vector<int>;

MATRIX subsets(const VEC& nums)
{
    MATRIX ans{};
    if(nums.size()==0)
        return ans;
    int n=nums.size();
    for(int i=0;i<(1<<n);++i)
    {
        VEC cur{};
        for(int j=0;j<n;++j)
        {
            if(i&(1<<j))
                cur.push_back(nums[j]);
        }
        ans.push_back(cur);
    }
    return ans;
}

int main()
{
    VEC nums{1,2,3};
    MATRIX res=subsets(nums);
    for(auto &v:res)
    {
        std::cout<<'\n';
        for(auto &i:v)
        {
            std::cout<<i<<',';
        }
    }
}