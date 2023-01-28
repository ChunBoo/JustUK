#include<iostream>
#include<vector>
#include<queue>  //for std::priority_queue  https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-ordered-by-first/ https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
#include<map>
#include<set>
using VEC=std::vector<int>;

using PAIR=std::pair<int,int>;
using PQ=std::priority_queue<PAIR>;
using MATRIX=std::vector<VEC>;
using MAP=std::map<int,MATRIX>;
using SET=std::set<int>;


template <typename K, typename V>
V GetWithDef(const  std::map <K,V> & m, const K & key, const V & defval ) 
{
    typename std::map<K,V>::const_iterator it = m.find( key );
    if ( it == m.end() ) 
        return defval;
    else 
        return it->second;
}

int dijkstra(const MATRIX& edges,int start,int stop)
{
    //convert the edges to Graph
    MAP G{};
    for(auto &e:edges)
    {
        G[e[0]].push_back(VEC{e[1],e[2]});
    }
    // PQ pq{std::make_pair(0,start)};
    // std::priority_queue<PAIR,std::vector<PAIR>,std::greater<PAIR>> pq;
    PQ pq{};
    pq.push(std::make_pair(0,start));

    SET seen{};
    int V=G.size();
    std::map<int,int> d{};  //this is map not vector
    // VEC d(V,INT_MAX);
    d[start]=0;
    while(!pq.empty())
    {
        PAIR top=pq.top();
        pq.pop();
        int c=top.first,v=top.second;
        if(seen.find(v)!=seen.end())
            continue;
        seen.insert(v);

        for(auto &e:G[v])
        {
            int x=e[0],w=e[1];
            int curCost=GetWithDef(d,x,INT_MAX);
            if((w+c)<curCost)
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
    {1, 2, 20},
    {0, 2, 92}};
    int start = 0,end = 2;
    std::cout<<dijkstra(edges,start,end);
}

