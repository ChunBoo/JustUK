#include<iostream>
#include<map>
#include<vector>
#include<queue>

using MATRIX=std::vector<std::vector<int>>;
using MAP=std::map<int,int>;

using PAIR=std::pair<int,int>;
using Q=std::queue<PAIR>;

void f(int r,int c, int x,MATRIX& m)
{
    int R=m.size();
    int C=m[0].size();
    Q q{};
    q.push(PAIR(r,c));
    MATRIX dirs{{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty())
    {
        PAIR cur=q.front();
        q.pop();
        for(auto &_m:dirs)
        {
            int rr=_m[0]+cur.first;
            int cc=_m[1]+cur.second;
            if(rr>=0 && rr<R && cc>=0 &&cc<C && m[rr][cc]==x)
            {
                m[rr][cc]=-1;
                q.push(PAIR(rr,cc));
            }
        }
    }
}

int steps(MATRIX &m)
{
    int R=m.size(),C=m[0].size();
    MAP data{};
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            if(m[r][c]!=-1)
            {
                int x=m[r][c];
                f(r,c,x,m);
                data[x]+=1;
            }
        }
    }

    //found the maximum values in data
    int _max=0,sum=0;
    for(auto &[k,v]:data)
    {
        sum+=v;
        if(v>_max)
            _max=v;
    }
    return sum-_max;
}

int main()
{
        MATRIX m{
    {1, 1, 1, 1},
    {2, 2, 2, 2},
    {1, 3, 1, 2}};
    std::cout<<steps(m);
}