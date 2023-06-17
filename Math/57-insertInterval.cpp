/**
 * You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

 * 
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto iter=intervals.begin();
        while(iter!=intervals.end() && newInterval[0]>(*iter)[0]) ++iter;
        intervals.insert(iter,newInterval);

        vector<vector<int>> ans{};
        for(auto interval:intervals)
        {
            if(ans.empty()||interval[0]>((ans.back())[1]))
                ans.push_back(interval);
            else
                (ans.back())[1]=max(interval[1],(ans.back())[1]);
        }
        return ans;
    }
};