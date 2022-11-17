#include<iostream>
#include<algorithm>
#include<vector>

using VEC=std::vector<int>;

bool isconsecutive(VEC nums)
{
    std::sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;++i)
    {
        if((nums[i+1]-nums[i])!=1)
            return false;
    }
    return true;
}

int main()
{
    VEC nums{2,4,4,5,3};
    std::cout<<isconsecutive(nums);
}