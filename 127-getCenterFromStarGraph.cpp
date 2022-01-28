#include<vector>
#include<iostream>
// #include "graph.h"
// [[1,2],[2,3]]
#include<map>

int getCenterOfStarG(const std::vector<std::vector<int>>& G)
{
    if((G[0][0]==G[1][0])||(G[0][0]==G[1][1]))
        return G[0][0];
    else
        return G[0][1];
}

int getCenterOfStar(const std::vector<std::vector<int>>& g)
{
    std::map<int,int> nb{};
    for(auto i:g)
    {
        for(auto j:i)
        {
            nb[j]+=1;
        }
    }
    int n=g.size();
    for(auto i:nb)
    {
        if(i.second==(n))
            return i.first; 

    }
}


int main()
{
    std::vector<std::vector<int>> g;//(5,(std::vector<int>(2)));
    std::vector<int> v1{1,2};
    std::vector<int> v2{3,2};
    std::vector<int> v3{4,2};
    std::vector<int> v4{5,2};
    std::vector<int> v5{6,2};
    g.push_back(v1);
    g.push_back(v2);
    g.push_back(v3);
    g.push_back(v4);
    g.push_back(v5);

    int res=getCenterOfStar(g);
    std::cout<<res<<'\n';
    return 0;
}