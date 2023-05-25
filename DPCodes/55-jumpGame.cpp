#include<iostream>
#include<vector>
#include<cmath>

using std::cout;
using VEC=std::vector<int>;


bool foo(const VEC &nums,int i)
{
    int n=nums.size();
    if(i>=n-1)
        return true;
    if(i+nums[i]>=n-1)
        return true;
    
    for(int s=1;s<nums[i]+1;++s)  //the end value should be nums[i]+1
    {
        if(foo(nums,s+i))
            return true;
    }
    return false;
}

int canJump(const VEC& nums)
{
    return foo(nums,0);
}

int main()
{
    VEC nums{3,2,1,0,4};
    cout<<canJump(nums);
}