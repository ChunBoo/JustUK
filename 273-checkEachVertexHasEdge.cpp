#include<iostream>
#include<vector>

using DT=std::vector<std::pair<int,int>>;
using PAIR=std::pair<int,int>;

bool isAllVertexHasEdge(const DT& e,int n)
{
    std::vector<bool> data(n,false);
    for(auto &i:e)
    {
        data[i.first]=data[i.second]=true;
    }
    for(auto i:data)
    {
        if(!i)
            return false;
    }
    return true;
}

int main()
{
    DT edges{PAIR(0,2),PAIR(1,4),PAIR(2,3)};
    std::cout<<isAllVertexHasEdge(edges,4);
}