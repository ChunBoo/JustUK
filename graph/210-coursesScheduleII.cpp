/**
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

 * 
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto& p:prerequisites)
            graph[p[1]].push_back(p[0]);
        
        //sts: 0=unknown, 1==visiting, 2==visited
        vector<int> v(numCourses,0);
        vector<int> ans;

        for(int i=0;i<numCourses;++i)
        {
            if(dfs(i,graph,v,ans)) return {};
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    bool dfs(int cur,vector<vector<int>>& graph,vector<int> &v,vector<int>& ans)
    {
        if(v[cur]==1)
          return true;
        if(v[cur]==2) return false;

        v[cur]=1;
        for(const int t:graph[cur])
          if(dfs(t,graph,v,ans)) return true;
        v[cur]=2;
        ans.push_back(cur);
        return false;
    }
};

int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequisites{{1,0},{2,1}};
    vector<int> res=Solution().findOrder(numCourses, prerequisites);
    for(auto v:res)
        cout<<v<<',';
}