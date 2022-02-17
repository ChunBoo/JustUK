//given a set,return the value if it can be splitted as two groups:
// 1.each group has same sum;
//2.elements of one group is strictly smaller than the other group

#include<vector>
#include<iostream>
#include<numeric> //for std::accumulate()

bool isCanBeSplittedAsTwoGroup(const std::vector<int>& nums)
{

    int sum=std::accumulate(nums.begin(),nums.end(),0);
    int c=0;
    int sz=nums.size();
    for(int i=0;i<sz;++i)
    {
        c+=nums[i];
        if((c*2==sum)&& nums[i]<nums[i+1])
            return true;
        if(c*2>sum)
            return false;
    }
    return false;
}

int main()
{
    std::vector<int> nums{2,3};
    bool res=isCanBeSplittedAsTwoGroup(nums);
    std::cout<<res<<'\n';
    return 0;
}

