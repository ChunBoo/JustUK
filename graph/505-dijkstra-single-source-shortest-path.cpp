#include<iostream>
#include<vector>
#include<queue>  //for std::priority_queue
#include<map>
#include<set>
using VEC=std::vector<int>;

using PAIR=std::pair<int,int>;
using PQ=std::priority_queue<PAIR>;
using MATRIX=std::vector<VEC>;
using MAP=std::map<int,MATRIX>;
using SET=std::set<int>;
int dijkstra(const MATRIX& edges,int start,int stop)
{
    MAP G{};
    for(auto &e:edges)
    {
        VEC tmp{e[1],e[2]};
        G[e[0]].push_back(tmp);
    }
    std::map<int,int> d{};

    d[start]=0;
    PQ pq{};
    SET seen{};
    pq.push(std::make_pair(0,start));
    while(!pq.empty())
    {
        PAIR top=pq.top();
        pq.pop();
        int c=top.first, v=top.second;
        if(seen.find(v)!=seen.end())
            continue;
        seen.insert(v);
        for(auto &vs:G[v])
        {
            int w=vs[1],x=vs[0];
            if((d[x]==0)||(w+c)<d[x])
            {
                d[x]=c+w;
                pq.push(std::make_pair(c+w,x));
            }
        }
    }
    return d[stop];
}

int main()
{
    MATRIX edges = {
    {0, 1, 3},
    {1, 2, 2},
    {0, 2, 9}};
    int start = 0,end = 2;
    std::cout<<dijkstra(edges,start,end);
}

