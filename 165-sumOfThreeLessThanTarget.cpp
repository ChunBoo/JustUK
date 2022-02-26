//given a vector of integers and one target
//return the counts of three numbers sum less than target 

#include<iostream>
#include<vector>
#include<algorithm>
int cntOfLessThanTarget(std::vector<int>& nums,int target)
{
    int ans=0;
    if(nums.empty())
        return ans;

    std::sort(nums.begin(),nums.end());

    int sz=nums.size();
    for(int f=0;f<sz;++f)
    { 
        int s=f+1,t=sz-1;
        while(s<=t)
        {
            int x=nums[f]+nums[s]+nums[t];
            if(x<target)
            {
                ans+=(t-s); 
                break;
            }
            else
                t-=1;
        }
    }
    return ans;
}


int main()
{
    std::vector<int> nums{2,3,4,1,6,7,9};
    int res=cntOfLessThanTarget(nums,10);
    std::cout<<res;
    return 0;
}