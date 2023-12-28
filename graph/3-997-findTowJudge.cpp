#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> g(n+1);
        for(const auto& t:trust)
        {
            g[t[0]].push_back(t[1]);
        }
        vector<int> tmp(n+1);
        for(const auto& t:g){
            if(t.empty())
                continue;
            for(const auto& v:t)
            {
            ++tmp[v];
            if(tmp[v]==n-1)
                return v;}
        }
        return -1;
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1);
        for(const auto&t:trust)
        {
            --degree[t[0]];
            ++degree[t[1]];
        }
        for(int i=1;i<n+1;++i)
        {
            if(degree[i]==n-1)
                return i;
        }
        return -1;
    }
};
int main()
{
    int n = 2;
    vector<vector<int>> trust = {{1,2}};
    cout<<Solution().findJudge(n,trust);
}