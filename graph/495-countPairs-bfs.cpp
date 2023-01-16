#include<iostream>
#include<set>
#include<map>
#include<deque>
#include<vector>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using MAP=std::map<int,VEC>;

using SET=std::set<int>;
using Q=std::deque<int>;

int bfoo(int i, MAP& G,SET& seen)
{
    if(seen.find(i)!=seen.end())
        return 0;
    int ans=0;
    Q q{i};
    while(!q.empty())
    {
        ans+=1;
        int cur=q.front();
        q.pop_front();
        for(auto v:G[cur])
        {
            if(seen.find(v)==seen.end())
            {
                seen.insert(v);
                q.push_back(v);
            }
        }
    }
    return ans;
}
void createGraph(const MATRIX& edges,MAP& G)
{
    for(auto &v:edges)
    {
        G[v[0]].push_back(v[1]);
        G[v[1]].push_back(v[0]);
    }
}
int countPairs(int n,const MATRIX& edges)
{
    MAP G{};
    createGraph(edges,G);
    SET seen{};
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(seen.find(i)==seen.end())
        {
            int cur=bfoo(i,G,seen);
            ans+=(n-cur)*cur;
        }
    }
    return ans/2;
}


int main()
{
    int n = 7;
    MATRIX edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    std::cout<<(countPairs(n,edges));
}