//line sweeping method to get the most frequency intervals 
//Line Sweeping Algorithm to Compute the Most Frequent Number in Intervals with the smallest value

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using DT=std::vector<std::vector<int>>;
using PAIR=std::pair<int,int>;
int mostFrequency(const DT& intervals)
{
    std::map<int,int> d{};
    for(int i=0;i<intervals.size();++i)
    {
        d[intervals[i][0]]+=1;
        d[intervals[i][1]+1]-=1;
    }
    int ans=0,most=0;
    std::map<int,int>::iterator iter=d.begin();
    for(;iter!=d.end();++iter)
    {
        if(most<iter->second)
        {
            most=iter->second;
            ans=iter->first;
        }
    }
    return ans;
}

int main()
{
    DT iterval{{1,4},{1,4}};
    std::cout<<mostFrequency(iterval);
    return 0;
}
