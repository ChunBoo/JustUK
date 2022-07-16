//given a edges lists,return true if two vertex has path 

#include<vector>
#include<set>
#include<iostream>
#include<map>
using DT=std::vector<std::pair<int,int>>; //for the edges

bool dfs(std::set<int>& seen,std::map<int,std::vector<int>>& G, int start,int end)
{

}

bool isPathExisted(const DT& edges,int s,int e)
{

}

int main()
{
    using PAIR=std::pair<int,int>;
    DT e{PAIR(1,2),PAIR(2,3),PAIR(2,4)};
    std::cout<<isPathExisted(e,1,4);
    return 0;
}