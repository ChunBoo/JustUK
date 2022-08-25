#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<set>
using GRAPH=std::map<char,std::vector<char>>;


void visit(char Node)
{
    std::cout<<Node;
}


void traversingGraphBFS( GRAPH& graph,char src)
{
    std::queue<char> q{};
    std::set<char> seen{};

    q.push(src);
    while(!q.empty())
    {
        char curNode=q.front();
        q.pop();
        visit(curNode);

        for(auto node:graph[curNode])
        {
            if(!seen.count(node))
            {
                seen.insert(node);
                q.push(node);
            }
        }
    }
}
/*
G={
    'A':['B','C','D'],
   'B':['E'],
   'C':[],
   'D':['E'],
   'E':['B','D']
   }
*/
int main()
{
    GRAPH g{};
    g['A']={'B','C','D'};
    g['B']={'E'};
    g['C']={};
    g['D']={'E'};
    g['E']={'B','D'};
    traversingGraphBFS(g,'A');
}

