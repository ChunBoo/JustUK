// check if a list is sequential: increasing or decreasing

#include<vector>
#include<iostream>

bool checkIsSequential(const std::vector<int>& nums)
{
    bool increasing=true;
    bool decreasing=true;

    int numSZ=nums.size();
    if(!numSZ || numSZ==1)
        return false;

    int i=0;
    while(i<numSZ-1)
    {
        if(nums[i]>nums[i+1])
            increasing=false;
        else if(nums[i]<nums[i+1])
            decreasing=false;
        ++i;
    }
    return increasing||decreasing;
}


int main()
{
    std::vector<int> nums{6,5,4,3,2,1};
    std::cout<<"list is sequential: "<<(checkIsSequential(nums)?"Yes":"No")<<'\n';

    return 0;
}