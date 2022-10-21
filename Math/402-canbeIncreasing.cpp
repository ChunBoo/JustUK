#include<iostream>
#include<vector>
#include<algorithm>  //
using VEC=std::vector<int>;


bool isIncreasing(VEC& nums)
{
    int n=nums.size();
    for(int i=0;i<n-1;++i)
    {
        if(nums[i]>nums[i+1])
            return false;
    }
    return true;
}

bool bruteForce(VEC& nums)
{
    int cnt=0,n=nums.size();
    for(int i=0;i<n;++i)
    {
        VEC tmp{};
         

        if(!isIncreasing(tmp))
            cnt+=1;
    }
    return cnt==1;
}

int main()
{
    VEC nums{1,2,5,3,4};
    std::cout<<bruteForce(nums);
}


bool canBeIncreasing(VEC& nums)
{
    int n=nums.size();
    VEC f(n,1);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(nums[j]<nums[i])
                f[i]=std::max(f[i],f[j]+1);
        }
    }
    return *(std::max(f.begin(),f.end()))+1==n;
}


int main()
{
    VEC nums{1,2,5,3,4};
    std::cout<<canBeIncreasing(nums);
}