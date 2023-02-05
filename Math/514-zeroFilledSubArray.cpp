#include<iostream>
#include<vector>

using std::cout;
using VEC=std::vector<int>;

int zeroFilledSubArray(const VEC& nums)
{
    int ans=0,z=0;
    for(auto &i:nums)
    {
        if(i==0)
        {
            z+=1;
            ans+=z;
        }
        else
            z=0;
    }
    return ans;
}

int main()
{
    VEC nums{1,3,0,0,2,0,0,4};
    cout<<zeroFilledSubArray(nums);
}