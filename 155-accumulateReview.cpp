//given a vector of nums, implement the codes which likes python's accumulate()

#include<vector>
#include<iostream>

using std::vector;

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
    vector<int> nums{1,2,3,4,5};
    myAccumulate(nums);
    for(auto i:nums)
        std::cout<<i<<',';
    
    return 0;
}