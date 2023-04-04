#include<algorithm>
#include<iostream>
#include<vector>

using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;

MATRIX mergeIntervals(MATRIX& intervals)
{
    MATRIX ans{};
    int n=intervals.size();
    if(n==1)
        return intervals;
    std::sort(intervals.begin(),intervals.end());

    int left=intervals[0][0],right=intervals[0][1];
    for(int i=1;i<n;++i)
    {
        if(right>=intervals[i][0])
            right=std::max(right,intervals[i][1]);
        else
        {
            ans.push_back({left,right});
            left=intervals[i][0];
            right=intervals[i][1];
        }
    }
    ans.push_back({left,right});
    return ans;
}

int main()
{
    MATRIX intervals{{1,3},{2,6},{8,16},{15,18}};
    MATRIX res=mergeIntervals(intervals);
    for(auto &_:res)
    {
        cout<<'[';
        for(auto v:_)
            cout<<v<<',';
        cout<<"]\n";
    }
}