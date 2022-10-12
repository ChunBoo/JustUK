#include<vector>
#include<iostream>
#include<numeric>
using VEC=std::vector<int>;
int checkIndex(const VEC& nums)
{
    int total=std::accumulate(nums.begin(),nums.end(),0);
    int left=0,right=total;
    for(int i=0;i<nums.size();++i)
    {

        right-=nums[i];
        if(left==right)
            return i;
        left+=nums[i];
    }
    return -1;
}

int main()
{
    VEC nums{2,3,4,0,5,2,2};
    std::cout<<checkIndex(nums);
}