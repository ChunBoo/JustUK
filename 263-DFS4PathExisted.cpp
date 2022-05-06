#include<vector>
#include<set>
#include<iostream>
#include<map>
using DT=std::vector<std::pair<int,int>>; //for the edges

bool dfs(std::set<int>& seen,std::map<int,std::vector<int>>& G, int start,int end)
{
    if(start==end)
        return true;
    seen.insert(start);
    for(auto i:G[start])
    {
        if(seen.find(i)==seen.end()&&dfs(seen,G,i,end))
            return true;
    }
}

bool isPathExisted(const DT& edges,int s,int e)
{
    if(s==e)
        return true;
    //created the adjacent list now
    std::map<int,std::vector<int>> G{};
    std::set<int> seen{};
    for(auto i:edges)
    {
        int s=i.first,E=i.second;
        G[s].push_back(E);
        G[E].push_back(s);
    }
    bool ans=false;
    ans=dfs(seen,G,s,e);

    return ans;
}
int main()
{
    using PAIR=std::pair<int,int>;
    DT e{PAIR(1,2),PAIR(2,3),PAIR(2,4)};
    std::cout<<isPathExisted(e,1,4);
    return 0;
}