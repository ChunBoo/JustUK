#include<set>
#include<algorithm>
#include<vector>
#include<iostream>


bool isArithmeticSequence(std::vector<int>& nums)
{
    std::sort(nums.begin(),nums.end());  //O(N*LOGN)
    std::set<int> d{};
    for(int i=1;i<nums.size();++i)
    {
        d.insert(nums[i]-nums[i-1]);
    }

    return d.size()==1;
}

int main()
{
    std::vector<int> nums{1,5,7,3,2};
    std::cout<<isArithmeticSequence(nums);
    return 0;
}