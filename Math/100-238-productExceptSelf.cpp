#include<iostream>
#include<vector>

using VEC=std::vector<int>;
using std::cout;


VEC productExceptSelf(const VEC& nums)
{
    int n=nums.size();
    VEC ans(n,0);
    int k=1;
    for(int i=0;i<n;++i)
    {
        ans[i]=k;
        k*=nums[i];
    }
    k=1;

    for(int i=n-1;i>=0;--i)
    {
        ans[i]*=k;
        k*=nums[i];
    }
    return ans;
}

int main()
{
    VEC nums{1,2,3,4};
    VEC res=productExceptSelf(nums);
    for(auto &v:res)
        cout<<v<<',';
}