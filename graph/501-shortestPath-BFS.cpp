#include<iostream>
#include<deque>
#include<vector>

#include<set>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;

using Que=std::deque<int>;
using SET=std::set<int>;

int bfoo(const MATRIX& G,int s,int e)
{
    if(s==e)
        return 0;
    SET seen{};
    Que q{s};
    int d=0;
    while(!q.empty())
    {
        d+=1;
        int len=q.size();
        for(int i=0;i<len;++i)
        {
            int cur=q.front();
            q.pop_front();
            if(seen.find(cur)!=seen.end())
                continue;
            if(cur==e)
                return d-1;
            seen.insert(cur);
            for(auto &vs:G[cur])
            {
                q.push_back(vs);
            }
        }
    }
    return -1;
}

int shortestDistance(const MATRIX& m,int s,int e)
{
    return bfoo(m,s,e);
}


int main()
{
    MATRIX   ports{{2, 3},{2},{1, 0},{4},{}};
    VEC ss{2, 4};
    std::cout<<shortestDistance(ports,ss[0],ss[1]);
}