/**
 * You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

 * 
*/
#include<iostream>
#include<vector>
#include<cmath>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using std::cout;

class Solution {
public:
    MATRIX insert(MATRIX& intervals, VEC& newInterval) {
        auto it=intervals.begin();
        //insert the new interval into intervals
        while(it!=intervals.end()&&newInterval[0]>(*it)[0]) ++it;
        intervals.insert(it,newInterval);
        //create new matrix to save the result
        MATRIX ans{};
        //iterate through all of the elements to merge newInterval into intervals
        for(auto & interval:intervals)
        {
            if(ans.empty()||interval[0]>ans.back()[1])
                ans.push_back(interval);
            else
                ans.back()[1]=std::max(interval[1],ans.back()[1]);

        }
        return ans;
    }
};

int main(){
   MATRIX intervals{{1,3},{6,9}};
   VEC newInterval{3,5};
   MATRIX ans=Solution().insert(intervals,newInterval);
   for(auto &v:ans)
   {
    cout<<'\n';
    for(auto &d:v)
        cout<<d<<",";
   }

}