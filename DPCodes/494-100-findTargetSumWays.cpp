#include<iostream>
#include<vector>
#include<numeric>
using std::cout;
using VEC=std::vector<int>;

int foo(const VEC& nums,int idx,int t)
{
    // if(t<0)
        // return 0;
    if(t<0)
    {
        if(idx==int(nums.size())) return 1;
        return 0;
    }
    if(t<nums[idx])
        return foo(nums,idx-1,t);
    return foo(nums,idx-1,t)+foo(nums,idx-1,t-nums[idx]);
}

int test(const VEC& nums,int t)
{
    // int n=nums.size();
    int sum=std::accumulate(nums.begin(),nums.end(),0);
    t+=sum;
    if(t<0 || t&1)
        return 0;
    t/=2;
    // int ans=0;
    return foo(nums,0,t); 
    // return ans;
}
int main()
{
    VEC nums{1,1,1,1,1};
    int target = 3;
    cout<<(test(nums,target));
}