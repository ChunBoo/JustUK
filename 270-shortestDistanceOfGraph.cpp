//given a graph which each edge has it's weight,return the shortest distance between two vertexes
//edges structure: {{1,2,5}}, weight of vertex 1 to 2 is 5
#include<vector>
#include<iostream>

using DT=std::vector<std::vector<int>>;
int getTotalVertexes(const DT& edges)
{
    int ans=0;
    for(auto &e:edges)
    {
        for(int i=0;i<e.size()-2;++i)
        {
            // std::cout<<i<<'\n';
            ans=std::max(ans,std::max(e[i],e[i+1]));
        }
    }
    return ans;
}
DT shortestDistance(const DT& edges )
{
    int vCnt=getTotalVertexes(edges);
    std::cout<<vCnt<<'\n';
}

int main()
{
    DT edges{{1,2,10},{2,3,50},{3,5,100}};
    shortestDistance(edges);
    return 0;
}