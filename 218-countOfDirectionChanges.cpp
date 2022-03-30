//given a list of numbers, return the count of directions changes
// likes [1,2,3,4,2,1],return 1

#include<vector>
#include<iostream>

using DT=std::vector<int>;
int countOfDirectionsChange(const DT& nums)
{
    int sz=nums.size();
    if(sz<=2)
        return 0;
    int slope=nums[1]-nums[0];
    int ans=0;
    for(int i=2;i<sz;++i)
    {
        int curSlope=nums[i]-nums[i-1];
        if(curSlope*slope<0)
            ans+=1;
        slope=curSlope;
    }
    return ans;
}

int main()
{
    DT list{1,2,3,4,3,5,1};
    std::cout<<countOfDirectionsChange(list);
    return 0;
}