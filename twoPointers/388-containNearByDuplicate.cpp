//given one vector with integers and one distance k
//check if there are two numbers are same and with distance is less than k?

#include<iostream>
#include<vector>
#include<map>
bool containNearByDuplicate(std::vector<int>& nums,int k)
{
    if(nums.empty() || k<1)
        return false;
    
    std::map<int,int> seen{};
    int n=nums.size();
    for(int i=0;i<n;++i)
    {
        if(seen.find(nums[i])!=seen.end())
        {
            if((i-seen[nums[i]])<=k)
                return true;
        }
        seen[nums[i]]=i;
    }
    return false;
}

int main()
{
    std::vector<int> nums{1,0,1,3};
    std::cout<<containNearByDuplicate(nums,1);
}