#include<map>
#include<vector>
#include<iostream>
#include<set>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using MAP=std::map<int,VEC>;
using SET=std::set<int>;

int dfs(int i, MAP& G,SET& seen)
{   
    if(seen.find(i)!=seen.end())
        return 0;
    int ans=1;
    seen.insert(i);
    const VEC temp=G[i];
    for(auto v:G[i])
    {
        ans+=dfs(v,G,seen);
    }
    return ans;
}

int countPair(int n,const MATRIX& edges)
{
    MAP G{};
    for(auto &v:edges)
    {
        G[v[0]].push_back(v[1]);
        G[v[1]].push_back(v[0]);
    }
    int ans=0;
    SET seen{};
    //get the vertex count for each group
    for(int i=0;i<n;++i)
    {
        if(seen.find(i)==seen.end())
        {
            int c=dfs(i,G,seen);
            ans+=(n-c)*c;
        }
    }
    return ans/2;
}

int main()
{
    int n = 7;
MATRIX edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
std::cout<<(countPair(n,edges));
}