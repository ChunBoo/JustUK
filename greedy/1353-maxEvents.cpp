/**
 * You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
 

Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        /*sort(begin(events),end(events),[](const auto&a, const auto&b){
            return a[1]<b[1];
        });
        int ans=0;
        char seen[100001]={0};
        for(const auto& e:events)
        {
            for(int i=e[0];i<=e[1];++i)
            {
                if(seen[i]) continue;
                ++seen[i];
                ans+=1;
                break;
            }
        }
        return ans;*/
        sort(begin(events),end(events),[](const auto&a,const auto&b){
            return a[1]<b[1];
        });
        int minD=INT_MAX, maxD=INT_MIN;
        for(const auto& e:events)
        {
            minD=min(minD,e[0]);
            maxD=max(maxD,e[1]);
        }
        vector<int> days(maxD-minD+1);
        iota(begin(days),end(days),minD);
        set<int> s(begin(days),end(days));

        int ans=0;
        for(const auto& e:events)
        {
            auto it=s.lower_bound(e[0]);
            if(it==end(s)||*it>e[1]) continue;
            s.erase(it);
            ans+=1;
        }
        return ans;
    }
};