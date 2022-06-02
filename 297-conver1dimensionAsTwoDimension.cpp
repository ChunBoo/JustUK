#include<iostream>
#include<vector>

using DT=std::vector<int>;
using RDT=std::vector<std::vector<int>>;


RDT getTwoDimensionArray(const DT& nums,int r,int c)
{
    
    if(nums.size()!=r*c)
        return RDT{};
    
    RDT ans(r,DT(c,0));

    int i=0;
    for(int rr=0;rr<r;++rr)
    {
        for(int cc=0;cc<c;++cc)
        {
            ans[rr][cc]=nums[i++];
        }
    }
    return ans;
}

int main()
{
    DT nums{1,3,5,7};
    RDT res=getTwoDimensionArray(nums,2,2);
    for(auto d:res)
    {
        std::cout<<'\n';
        for(auto i:d)
            std::cout<<i<<',';
    }
    return 0;
}

