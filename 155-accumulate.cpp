#include<vector>
#include<iostream>
using std::vector;
std::vector<int> accumulate(std::vector<int>& nums)
{
    int sz=nums.size();
    
    std::vector<int> ans(sz,0);
    if(sz==0)
        return ans;
    int sum=0;
    for(int i=0;i<sz;++i)
    {
        sum+=nums[i];
        ans[i]=sum;
    }
    return ans;
}

void myAccumulate(vector<int>& nums)
{
    int sz=nums.size();
    if(sz==0)
        return ;
    // int sum=0;
    for(int i=1;i<sz;++i)
    {
        // sum+=nums[i];
        nums[i]+=(nums[i-1]);
    }

}
int main()
{
    std::vector<int> nums{1,2,3,4,5};
    std::vector<int> res=accumulate(nums);
    for(auto i: res)
        std::cout<<i<<',';
    return 0;
}