#include<vector>
#include<iostream>
#include<numeric>  //for std::accumulate()
#include<algorithm>
#include<cmath>
using VEC=std::vector<int> ;
long sumOfGP( VEC& nums)
{
    return std::accumulate(nums.begin(),nums.end(),0);
}

long sumOfGp(const VEC& nums)
{
    if(nums.empty())
        return 0;
    
    int sz=nums.size();
    if(sz==1)
        return nums[0];
    long ret=0;
    int q=nums[1]/nums[0];
    for(int i=0;i<sz;++i)
        ret+=std::pow(q,i)*nums[0];
    return ret;
}

int main()
{
    VEC nums{};
    for(int i=0;i<9;++i)
        nums.push_back(2*std::pow(2,i));
    for(auto &i:nums)
        std::cout<<i<<" , ";
    std::cout<<sumOfGP(nums);
    std::cout<<sumOfGp(nums);
}