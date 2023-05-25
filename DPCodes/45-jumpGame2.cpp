#include<vector>
#include<iostream>
#include<cmath>

using std::cout;
using VEC=std::vector<int>;

int foo(int i,const VEC& nums)
{
    int n=nums.size();
    if(i>=n-1)
        return 0;
    if(i+nums[i]>=n-1)   //pruning,剪枝以减少时间规模
        return 1;
    
    int ans=n;
    for(int s=1;s<nums[i]+1;++s)
    {
        ans=std::min(ans,foo(i+s,nums)+1);
    }
    return ans;
}

int jumpGame(const VEC& nums)
{
    // int n=nums.size();
    return foo(0,nums);
}

int main()
{
    VEC nums{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout<<jumpGame(nums);
}