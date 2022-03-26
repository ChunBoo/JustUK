#include<vector>
#include<algorithm>
#include<iostream>
#include <cmath>
using MATRIX=std::vector<std::vector<int>>;
int longestIntervals(MATRIX& nums)
{
    if(nums.empty())
        return 0;
    
    std::sort(nums.begin(),nums.end());

    int start=nums[0][0],end=nums[0][1];
    int sz=nums.size();
    int ans=end-start+1;
    for(int i=1;i<sz;++i)
    {
        int newStart=nums[i][0];
        int newEnd=nums[i][1];
        if(newStart>start)
            start=newStart;
        end=std::max(end,newEnd);
        ans=std::max(ans,end-start+1);
    }
    return ans;
}

int main()
{
    MATRIX nums{{1,3},{2,3},{5,6}};
    std::cout<<longestIntervals(nums)<<'\n';
    return 0;
}