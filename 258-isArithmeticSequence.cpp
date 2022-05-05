#include<set>
#include<algorithm>
#include<vector>
#include<iostream>

bool isArithmeticSequence2(std::vector<int>& nums)//with set
{
    std::sort(nums.begin(),nums.end());
    std::set<int> d{};
    for(int i=1;i<nums.size();++i)
    {
        d.insert(nums[i]-nums[i-1]);
    }
    return d.size()==1;
}


bool isArithmeticSequence(std::vector<int>& nums)  //without  set
{
    int sz=nums.size();
    std::sort(nums.begin(),nums.end());
    for(int i=1;i<sz;++i)
    {
        if(nums[i]-nums[i-1]!=nums[1]-nums[0])
            return false;
    }
    return true;
}

int main()
{
    std::vector<int> nums{1,5,7,3,4};
    std::cout<<isArithmeticSequence2(nums);
    return 0;
}