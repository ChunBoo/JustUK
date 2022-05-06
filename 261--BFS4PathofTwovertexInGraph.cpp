//given a graph,likes [(1,2),(2,3)],to return true if two vertex has path 

#include<iostream>
#include<deque>
#include<set>
#include<vector>
#include<map>
using  DT=std::vector<std::pair<int,int>>;
using  PAIR=std::pair<int,int>;
bool isExistedPath(const DT& edges,int start,int end)
{
    //create the adjacent list
    std::map<int,std::vector<int>> G{};
    for(auto i:edges)
    {
        int s=i.first,e=i.second;
        G[s].push_back(e);
        G[e].push_back(s);
    }
    std::set<int> seen{};
    std::deque<int> q{};
    q.push_back(start);
    while(!q.empty())
    {
        int c=q.front();
        q.pop_front();
        if(c==end)
            return true;
        if(seen.find(c)!=seen.end())
            continue;
        seen.insert(c);  //this step is important!!!
        for(auto i:G[c])
            q.push_back(i);

    }
    return false;

}

int main()
{
    DT e{PAIR(1,2),PAIR(2,3),PAIR(2,4)};
    std::cout<<isExistedPath(e,1,5);
    return 0;
}