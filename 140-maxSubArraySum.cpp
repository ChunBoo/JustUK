#include<vector>
#include<iostream>
#include<cmath>  //for std::max()




int DPForMaxSubArraySum(const std::vector<int>& nums)
{
    //if currentValue+sum is larger than current value,then use currentValue+Sum,otherwise,we should use current value
    if(nums.empty())
        return -1;
    int ans=0;
    int sum=0;
    for(auto i:nums)
    {
        sum=std::max(sum+i,i);
        ans=std::max(sum,ans);
    }
    return ans;
}

int GreedyForMaxSubArraySum(const std::vector<int>& nums)
{
    //if current sum is negative,then used the new value
    if(nums.empty())
        return -1;
    
    int ans=0;
    int sum=0;
    for(auto i:nums)
    {
        //sum+=i;  //this step is wrong,should check current sum value firstly.
        if(sum<0)
            sum=i;
        else
            sum+=i;
        ans=std::max(ans,sum);
    }
    return ans;
}


int main()
{
    std::vector<int> nums{1,2,-2,1,-3};
    int dpRes=DPForMaxSubArraySum(nums);
    int greedyRes=GreedyForMaxSubArraySum(nums);
    std::cout<<dpRes<<'\n';
    std::cout<<greedyRes<<'\n';
    return 0;
}