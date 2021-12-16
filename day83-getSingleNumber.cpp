//given a array which contains a single number ,others are pairs 

#include<vector>
#include<iostream>
#include<algorithm>
int getSingleNumber( std::vector<int>& nums)
{
    if(nums.empty())
        return -1;
    std::sort(nums.begin(),nums.end());
    int ans=0;
    for(auto i:nums)
    {
        ans^=i;
    }
    return ans;
}


int main()
{
    std::vector<int> nums{1,1,3,3,2,2,8,8,0};
    int result=getSingleNumber(nums);
    std::cout<<"The single number is:"<<result<<'\n';
    return 0;
}