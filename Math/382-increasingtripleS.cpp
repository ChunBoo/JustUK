#include<vector>
#include<iostream>

using VEC=std::vector<int>;

bool isIncreasingTriples(VEC& nums)
{
    int a=INT_MAX;
    int b=INT_MAX;
    for(auto &v:nums)
    {
        if(v<=a)
            a=v;
        else if(v<=b)
            b=v;
        else
            return true;
    }
    return false;
}

int main()
{
    VEC nums{1,0,-1,2,0,4,5};
    std::cout<<isIncreasingTriples(nums);
    return 0;
}