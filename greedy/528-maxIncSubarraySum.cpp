#include<iostream>
#include<vector>
using std::cout;
using VEC=std::vector<int>;

int maxIncreasingSubArraySum(const VEC& nums)
{
    if(nums.empty())
        return 0;
    int n=nums.size();

    int cur=nums[0],ans=nums[0];

    for(int i=1;i<n;++i)
    {
        if(nums[i]>nums[i-1])
            cur+=nums[i];
        else
            cur=nums[i];
        ans=std::max(ans,cur);
    }
    return ans;
}

int main()
{
    VEC arr={10,20,30,5,10,50};
    cout<<maxIncreasingSubArraySum(arr);
}