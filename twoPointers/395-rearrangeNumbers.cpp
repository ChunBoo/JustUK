#include<vector>
#include<iostream>

using VEC=std::vector<int>;


VEC rearrangeNumbers(const VEC& nums)
{
    int sz=nums.size();
    VEC ans(sz,0);
    int p=0,n=1;
    for(int i=0;i<sz;++i)
    {
        if(nums[i]>0)
        {
            ans[p]=nums[i];
            p+=2;
        }
        else
        {
            ans[n]=nums[i];
            n+=2;
        }
    }
    return ans;
}

int main()
{
    VEC nums{3,1,-2,-5,2,-4};
    VEC res=rearrangeNumbers(nums);
    for(auto &v:res)
        std::cout<<v<<',';
}