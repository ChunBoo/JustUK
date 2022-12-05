#include<iostream>
#include<vector>
#include<cmath>
using VEC=std::vector<int>;

VEC sortedSquars(const VEC& nums)
{
    int n=nums.size();
    int l=0,r=n-1;

    int i=n-1;
    VEC ans(n,0);
    while(i>=0)
    {
        if(std::abs(nums[l])>std::abs(nums[r]))
        {
            ans[i]=std::pow(nums[l],2);
            l+=1;
        }
        else
        {
            ans[i]=std::pow(nums[r],2);
            r-=1;
        }
        i-=1;
    }
    return ans;
}

int main()
{
    VEC nums{-5,-1,0,3,4,7};
    VEC res=sortedSquars(nums);
    for(auto &v:res)
        std::cout<<v<<',';
}