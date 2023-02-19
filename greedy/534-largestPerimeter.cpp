#include<iostream>
#include<vector>
#include<algorithm>  //std::sort
using std::cout;
using VEC=std::vector<int>;

int largestPerimeter( VEC& nums)
{
    std::sort(nums.begin(),nums.end(),std::greater<int>());

    int n=nums.size();
    for(int i=0;i<n;++i)
    {
        if(nums[i+1]+nums[i+2]>nums[i])
            return nums[i]+nums[i+1]+nums[i+2];
    }
    return -1;
}
int main()
{
    VEC nums{2,1,2};
    cout<<largestPerimeter(nums);
}