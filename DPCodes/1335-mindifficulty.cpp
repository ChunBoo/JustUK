/**
 * 
 * You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.
Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 

*/
#include<iostream>
#include<vector>
#include<cmath>

using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;

class Solution {
public:
    int minDifficulty(VEC& jobs, int d) {
        const int n=jobs.size();
        if(n<d)
            return -1;
        
        MATRIX dp(n+1,std::vector<int>(d+1,INT_MAX/2));
        dp[0][0]=0;
        for(int i=1;i<=n;++i)
        {
            for(int k=1;k<=d;++k)
            {
                int md=0;
                for(int j=i-1;j>=k-1;--j)
                {
                    md=std::max(md,jobs[j]);
                    dp[i][k]=std::min(dp[i][k],dp[j][k-1]+md);
                }
            }
        }
        return dp[n][d];
    }
};

int main()
{
    VEC jobs{6,5,4,3,2,1};
    int d=2;
    cout<<Solution().minDifficulty(jobs,d);
}