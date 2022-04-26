#include<vector>
#include<iostream>
#include<map>
//return the count of sublist which has some header and tail.

int countWithTwoLoops(std::vector<int>& nums)
{
    int sz=nums.size(),ans=0;
    for(int L=0;L<sz;++L)
    {
        for(int R=L;R<sz;++R)
        {
            if(nums[L]==nums[R])
                ans+=1;
        }
    }
    return ans;

}
int countOfSubList(std::vector<int>& nums)
{
    int ans=0;
    std::map<int,int> seen{};
    for(auto i:nums)
    {
        seen[i]+=1;
        ans+=seen[i];
    }
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,3,5,1};
    std::cout<<countWithTwoLoops(nums);
    return 0;
}