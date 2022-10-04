#include<queue>
#include<functional>
#include<vector>
#include<iostream>
#include<map>
#include<set>
using MATRIX=std::vector<std::vector<int>>;
using PAIR=std::pair<int,int>;

int shortestGraph(MATRIX& m)
{
    std::map<int,MATRIX> G{};

    for(auto g:m)
    {
        for(int i=0;i<3;++i)
        { 
            std::vector<int> temp{g[1],g[2]};
            G[g[0]].push_back(temp);
        }
    }

    std::set<int> seen{};
    std::priority_queue
}

