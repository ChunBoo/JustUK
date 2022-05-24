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
        d[intervals[i][1]]-=1;
    }
    int ans=0;
    std::map<int,int>::iterator iter=d.begin();  //the map is ordered by key
    return iter->second;
}

int main()
{
    DT iterval{{1,2},{2,3}};
    std::cout<<mostFrequency(iterval);
    return 0;
}
