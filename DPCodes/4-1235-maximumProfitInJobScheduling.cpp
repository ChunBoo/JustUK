/***
 * We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int n=startTime.size();
        // vector<vector<int>> jobs(n);
        // for(int i=0;i<n;i++){
        //     jobs[i]={startTime[i],endTime[i],profit[i]};
        // }

        // sort(jobs.begin(),jobs.end(),[](const vector<int> &j1, const vector<int> &j2)->bool{
        //     return j1[1]<j2[1];
        // });

        // vector<int> dp(n+1);
        // for(int i=1;i<=n;i++)
        // {
        //     int k=upper_bound(jobs.begin(),jobs.begin()+i-1,jobs[i-1][0],[&](int start,const vector<int> &job) -> bool{
        //         return start<job[1];
        //     })-jobs.begin();
        //     dp[i]=max(dp[i-1],dp[k]+jobs[i-1][2]);
        // }
        // return dp[n];

        vector<vector<int>> jobs(n);
        for(int i=0;i<n;i++){
            jobs[i]={endTime[i],startTime[i],profit[i]};
        }
        sort(begin(jobs),end(jobs));
        
        map<int,int> m{{0,0}};//{end Time:maxProfit}
        for(const auto& j:jobs){
            int p=prev(m.upper_bound(j[1]))->second+j[2];
            if(p>rbegin(m)->second)
                m[j[0]]=p;
        }
        return rbegin(m)->second;
    }
};