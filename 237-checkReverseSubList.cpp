#include<vector>
#include<iostream>
#include<algorithm>
bool check(std::vector<int>& nums)
{
    std::vector<int> arr=nums;
    std::sort(arr.begin(),arr.end());

    int L=0,R=arr.size()-1;
    while(L<R&&arr[L]==nums[L])
        ++L;
    while(L<R&&arr[R]==nums[R])
        --R;
    int i=L,j=R;
    for(;i<=R&&j>=L;++i,--j)
    {
        if(arr[j]!=nums[i])
            return false;
    }
    return true;
}

int main()
{
    std::vector<int> nums{3,4,6,7,5,8,9};
    std::cout<<check(nums);
    return 0;
}
