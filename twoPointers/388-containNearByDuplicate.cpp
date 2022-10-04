#include<iostream>
#include<vector>
#include<map>
bool containNearByDuplicate(std::vector<int>& nums,int k)
{
    int j=0;
    int n=nums.size();
    std::map<int,int> seen{};
    for(int i=0;i<n;++i )
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
    std::vector<int> nums{1,0,1,1};
    std::cout<<containNearByDuplicate(nums,1);
}