//given edges of a graph,return true if there is vertex without edge,or return false
//algorithm is: define one vector to record each vertex's value: if has edge,then it is true

#include<iostream>
#include<vector>

using DT=std::vector<std::pair<int,int>>;
using PAIR=std::pair<int,int>;

bool isAllVertexHasEdge(const DT& e,int n)
{
    std::vector<bool> data(n,false);
    for(auto &p:e)
    {
        data[p.first]=data[p.second]=true;
    }

    for(int i=0;i<data.size();++i)
    {
        if(!data[i])
        {
            std::cout<<i<<'\n';
            return false;
        }
    }
    return true;
}

int main()
{
    DT edges{PAIR(1,2),PAIR(1,4),PAIR(2,4)};
    std::cout<<isAllVertexHasEdge(edges,4);
}