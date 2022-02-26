//given a vector with unique numbers, return true if we can find 4numbers sum equal to target

#include<vector>
#include<iostream>

bool sumOfFour(std::vector<int>& nums,int target)
{
    if(nums.empty())
        return false;

    int sz=nums.size();

    for(int i=0;i<sz;++i)
    {
        for(int j=i;j<sz;++j)
        {
            int third=j+1,forth=sz-1;
            while(third<=forth)
            {
                int x=nums[i]+nums[j]+nums[third]+nums[forth];
                if(x==target)
                    return true;
                if(x<target)
                    third+=1;
                else
                    forth-=1;
            }
        }
    }
    return false;
}


int main()
{
    std::vector<int> nums{1,2,3,4,5,6,7,9,10};
    std::cout<<sumOfFour(nums,81);
    return 0;
}