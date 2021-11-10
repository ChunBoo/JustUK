#include<iostream>
#include<vector>

std::vector<int> intervalsInterSection(std::vector<std::vector<int>>& intervals)
{
    std::vector<int> ret;
    if(intervals.empty())
        return ret;
    
    int left=intervals[0][0];
    int right=intervals[0][1];

    for(auto i: intervals)
    {
        int max=i[0];
        int min=i[1];
        if(left<max)
            left=max;
        if(right>min)
            right=min;
        
    }
    if(left>right)
        return ret;
    ret.push_back(left);
    ret.push_back(right);
    return ret;
}


int main()
{
    std::vector<std::vector<int>> intervals{{1,5},{4,7}};
    std::vector<int> ret=intervalsInterSection(intervals);
    std::cout<<"[ ";
    for(auto i:ret)
    {
        std::cout<<i<<",";
    }
    std::cout<<"]";

    return 0;
}